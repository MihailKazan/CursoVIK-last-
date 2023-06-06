#pragma once
#include "BearLibTerminal.h"
#include <map>
#include <vector>

using namespace std;

//void Ships();

struct Value {

	map <int, vector <int>> ships;
	vector <int> value;

	void Func(int j, int num, int xmin, int ymin, int xmax, int ymax);
	
	void Draw();

	bool Check2(int x , int y);

	void Rand(int* x, int* y, int* die, int xmin, int ymin,int xmax, int ymax);

	int Proof(int x, int y);
};
