#include "Ships.h"
#include "Windows.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

bool Check1(int x, int y, int rranx, int lranx, int urany, int drany) { //range
	if ((lranx < x && x < rranx) && (urany < y && y < drany)) {
		return 0;
	}
	else {
		return 1;
	}
}

bool Value :: Check2(int x, int y) {
	for (int i = 0; i < value.size(); i += 2) {
		if (x == value[i] && y == value[i + 1]) {
			return 1;
		}
	}
	return 0;
}

void Value::Rand(int* x, int* y, int* die, int xmin, int ymin, int xmax, int ymax) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist;
	do{
		*x = dist(gen) % xmax;
	} while (*x % 2 != 0 || *x <= xmin);
	do {
		*y = dist(gen) % ymax;
	} while (*y <= ymin);
	*die = dist(gen) % 4;

}

void Value::Func(int j, int num, int xmin, int ymin, int xmax, int ymax) {
	int x, y, die;
	for (int c = 0; c < num; c++) {
		bool Good = true;
		while (Good) {
			Rand(&x, &y, &die, xmin, ymin, xmax, ymax);
			switch (die)
			{
			case 0:
				for (int i = 0; i < j; i++) {
					ships[j].push_back(x - 2 * i);
					ships[j].push_back(y);
				}
				break;
			case 1:
				for (int i = 0; i < j; i++) {
					ships[j].push_back(x);
					ships[j].push_back(y - i);
				}
				break;
			case 2:
				for (int i = 0; i < j; i++) {
					ships[j].push_back(x + 2 * i);
					ships[j].push_back(y);
				}
				break;
			case 3:
				for (int i = 0; i < j; i++) {
					ships[j].push_back(x);
					ships[j].push_back(y + i);
				}
				break;
			}
			for (int i = c * 2 * j; i < j * 2 + c * 2 * j; i += 2) {
				if (Check1(ships[j][i], ships[j][i + 1], xmax, xmin-1, ymin, ymax) || Check2(ships[j][i], ships[j][i + 1])) {
					
					ships[j].resize(ships[j].size() - j * 2);
					break;
				}
				if (i == j * 2 + c * 2 * j - 2) {
					Good = false;
					for (int q = 0; q < ships[j].size() / 2; q++) {
						value.push_back(ships[j][q * 2]);
						value.push_back(ships[j][q * 2 + 1]);
						//
						value.push_back(ships[j][q * 2] - 2);
						value.push_back(ships[j][q * 2 + 1] - 1);

						value.push_back(ships[j][q * 2]);
						value.push_back(ships[j][q * 2 + 1] - 1);

						value.push_back(ships[j][q * 2] + 2);
						value.push_back(ships[j][q * 2 + 1] - 1);

						value.push_back(ships[j][q * 2] - 2);
						value.push_back(ships[j][q * 2 + 1]);

						value.push_back(ships[j][q * 2] + 2);
						value.push_back(ships[j][q * 2 + 1]);

						value.push_back(ships[j][q * 2] - 2);
						value.push_back(ships[j][q * 2 + 1] + 1);

						value.push_back(ships[j][q * 2]);
						value.push_back(ships[j][q * 2 + 1] + 1);

						value.push_back(ships[j][q * 2] + 2);
						value.push_back(ships[j][q * 2 + 1] + 1);
					}
				}
			}
		}
	}
	/*for (int i = 0; i < num * j; i++) {
		cout << i*2 << " " << ships[j][i * 2] << " " << ships[j][i * 2 + 1] << endl;
	}*/
}
void Value :: Draw() {
	for (int j = 1; j < 5; j++) {
		for (int i = 0; i < ships[j].size() / 2; i++) {
			terminal_printf(ships[j][i * 2], ships[j][i * 2 + 1], "#");
		}
	}
}

int Value::Proof(int x, int y) {
	for (int j = 1; j < 5; j++) {
		for (int i = 0; i < ships[j].size() / 2; i++) {
			if (x == ships[j][i * 2] && y == ships[j][i * 2 + 1]) {
				return 1;
			}
		}
	}
	return 0;
}

 //12 32
 //4  14
