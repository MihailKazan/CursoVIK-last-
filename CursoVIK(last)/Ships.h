#pragma once
#include "BearLibTerminal.h"
#include <map>
#include <vector>

using namespace std;

struct Value {

	map <int, vector <int>> ships;
	vector <int> value; // значения куда нельзя ставить корабли
	vector <int> separat; // проверка на убийство корабля

	void Func(int j, int num, int xmin, int ymin, int xmax, int ymax);
	
	void Draw();

	bool Check2(int x , int y);

	void Rand(int &x, int &y, int &die, int xmin, int ymin,int xmax, int ymax);

	int Proof(int x, int y);

	int Proof2(int x, int y,vector <int> &point);

	void SeparatNull(); // бля просто занулить так надо
};
