#include "BearLibTerminal.h"
#include "Map.h"
#include "Ships.h"
#include <iostream>
#include <string>
#include <vector>

#include "MyForm.h"
#include "Saver.h"
#include <Windows.h>
#include <math.h>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

bool Continue = true;

int Check(vector <int> vecx, vector <int> vecy, int x, int y) {
	for (int i = 0; i < vecx.size(); i++) {
		if (vecx[i] == x && vecy[i] == y) {
			return 0;
		}
	}
	return 1;
}

struct Play : Value {
	int I = 0;
	vector <int> X1;
	vector <int> Y1;
	vector <int> X2;
	vector <int> Y2;
	void Player(int a, int b, int minx, int maxx, int miny, int maxy,int num) {
		bool miss = false;
		int x, y;
		x = a;
		y = b;
		terminal_open();
		terminal_set("0x02B: cursor.png, size=16x16");//+
		terminal_printf(a, b, "+");
		while (1) {
			terminal_clear();
			getMap();
			//Draw();
			if (terminal_has_input) {
				int cours = terminal_read();
				switch (cours) {
				case (82):
					if (y > miny)
						y--;
					break;
				case (79):
					if (x < maxx) 
						x += 2;
					break;
				case (81):
					if (y < maxy) 
						y++;
					break;
				case (80):
					if (x > minx) 
						x -= 2;
					break;
				case (40):
					if (Proof(x,y)) {
						if (Check(X1, Y1, x, y)) {
							I++;
						}
						X1.push_back(x);
						Y1.push_back(y);
					}
					else {
						X2.push_back(x);
						Y2.push_back(y);
						miss = true;
					}
					break;
				case(41):
					Continue = false;
					return;
					break;
				}
			}
			terminal_set("0x058: ship.png, size=16x16");//X
			terminal_set("0x04F: miss.png, size=16x16");//O
			terminal_printf(x, y, "+");
			for (int q = 0; q < X1.size(); q++) {
				terminal_printf(X1[q], Y1[q], "X");
			}
			for (int q = 0; q < X2.size(); q++) {
				terminal_printf(X2[q], Y2[q], "O");
			}
			terminal_refresh();
			if (I == 20) {
				string win = "WINS PLAYER " + to_string(num) + " !";
				terminal_printf(30, 20, win.c_str());
				terminal_refresh();
				exit;
			}
			if (miss) {
				return;
			}
		}
	}
};

[STAThreadAttribute]

int main() { // 79 24////////////////////////////////////////
	setlocale(LC_ALL, "rus");

	bool Good = true;

	while (Good) {
		Play Exm1;
		Play Exm2;

		Exm1.Func(1, 4, 11, 3, 32, 14);
		Exm1.Func(2, 3, 11, 3, 32, 14);
		Exm1.Func(3, 2, 11, 3, 32, 14);
		Exm1.Func(4, 1, 11, 3, 32, 14);

		Exm2.Func(1, 4, 47, 3, 63, 14);
		Exm2.Func(2, 3, 47, 3, 63, 14);
		Exm2.Func(3, 2, 47, 3, 63, 14);
		Exm2.Func(4, 1, 47, 3, 63, 14);

		HDC hdc = GetDC(GetConsoleWindow());
		Saver();
		system("cls");
		int Inp = 0;
		int Y = 0, i = 0, Y0 = 10; // Y - переключаться между пунктами, i - счётчик
		HBRUSH BRUSH = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, BRUSH);

		gotoxy(56, 5);
		cout << "Морской бой" << endl;
		gotoxy(56, 8);
		cout << "Калькулятор" << endl;
		gotoxy(56, 11);
		cout << "Сведения об авторе" << endl;
		gotoxy(56, 14);
		cout << "Назад" << endl;
		gotoxy(0, 0);
		cout << " ";
		while (1) { // хорошо бы добавить точку в начале

			Continue = true;

			BRUSH = CreateSolidBrush(RGB(255, 255, 255)); // смена цвета белый
			SelectObject(hdc, BRUSH);

			Inp = _getche();

			if (Inp == 80 && i < 3) {
				Y0 = Y;
				Y++;
				i++;
			}
			else if (Inp == 72 && i > 0) {
				if (Y != 0) {
					Y0 = Y;
				}
				Y--;
				i--;
			}

			Ellipse(hdc, 430, 84 + 48 * Y, 440, 94 + 48 * Y);
			BRUSH = CreateSolidBrush(RGB(0, 0, 0)); // смена цвета чёрный
			SelectObject(hdc, BRUSH);
			Ellipse(hdc, 430, 84 + 48 * Y0, 440, 94 + 48 * Y0);
			Rectangle(hdc, 0, 0, 1000, 16);

			if (Inp == 13) {
				if (Y == 0) {
					system("cls");
					while (Continue) {
						Exm1.Player(22, 8, 12, 29, 4, 13, 1);
						if (Continue == false) {
							terminal_clear();
							terminal_close();
							break;
						}
						Exm2.Player(58, 8, 48, 66, 4, 13, 2);
					}
					break;
				}
				if (Y == 1) {
					Application::SetCompatibleTextRenderingDefault(false);
					Application::EnableVisualStyles();
					CursoVIKlast::MyForm form;
					Application::Run(% form);
					break;
					break;
				}
				if (Y == 2) {
					system("cls");
					while (1) {
						gotoxy(50, 5);
						cout << "ОмГТУ, ФИТиКС, ИВТ-223" << endl;
						gotoxy(50, 8);
						cout << "Курсовая работа по программированию" << endl;
						gotoxy(50, 11);
						cout << "Казанцев Михаил Сергеевич" << endl;
						if (_kbhit()) {
							if (_getche() == 27) {
								break;
							}
						}
					}
					break;
				}
				if (Y == 3) {
					system("cls");
					break;
				}
			}
		}
	}
}

//12 30
//4  13
