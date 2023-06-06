#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

void line(HDC hdc, int x1, int y1, int x2, int y2) { // отрисовка линии по координатам 
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // вывод делений
}

void Saver() {
	int x = 0, y = 0;
	bool Dix = true, Diy = true;

	while (1) {
		system("cls");
		HBRUSH BRUSH = CreateSolidBrush(RGB(255, 255, 255));// создание кисти белая
		HDC hdc = GetDC(GetConsoleWindow());
		SelectObject(hdc, BRUSH);

		Rectangle(hdc, 0 + x, 0 + y, 100 + x, 110 + y); // главный прямоугольник
		BRUSH = CreateSolidBrush(RGB(0, 0, 0)); // смена цвета чёрный
		SelectObject(hdc, BRUSH);

		Ellipse(hdc, 20 + x, 20 + y, 80 + x, 80 + y);
		Rectangle(hdc, 0 + x, 5 + y, 15 + x, 20 + y);
		Rectangle(hdc, 85 + x, 5 + y, 100 + x, 20 + y);
		Rectangle(hdc, 0 + x, 80 + y, 15 + x, 95 + y);
		Rectangle(hdc, 85 + x, 80 + y, 100 + x, 95 + y);

		Rectangle(hdc, 5 + x, 2 + y, 95 + x, 7 + y);
		Rectangle(hdc, 7 + x, 95 + y, 95 + x, 100 + y);

		Ellipse(hdc, 0 + x, 84 + y, 15 + x, 99 + y);// нижнии
		Ellipse(hdc, 85 + x, 85 + y, 100 + x, 100 + y);
		Ellipse(hdc, 0 + x, 2 + y, 15 + x, 17 + y);// верхнии
		Ellipse(hdc, 85 + x, 2 + y, 100 + x, 17 + y);

		for (float i = 0; i < 11; i += 1)
		{
			line(hdc, 40 + i + x, 100 + i + y, 60 - i + x , 100 + i + y);
		}

		BRUSH = CreateSolidBrush(RGB(255, 255, 255)); // смена цвета белый
		SelectObject(hdc, BRUSH);
		Rectangle(hdc, 31 + x, 31 + y, 69 + x, 69 + y);

		//SetPixel(hdc, 960, 10, RGB(255, 255, 255));

		if (x >= 860) {
			Dix = 0;
		}
		if (x < 0) {
			Dix = 1;
		}
		if (Dix == 1) {
			x+=2;
		}
		if (Dix == 0) {
			x-=2;
		}
		if (y >= 370) {
			Diy = 0;
		}
		if (y < 0) {
			Diy = 1;
		}
		if (Diy == 1) {
			y+=2;
		}
		if (Diy == 0) {
			y-=2;
		}
		Sleep(1);

		if (_kbhit()) {// вход по Enter
			if (_getch() == 13) {
				return;
			}
		}
	}
}
