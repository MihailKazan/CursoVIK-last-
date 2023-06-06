#include "Map.h"
#include <iostream>
#include <string>
using namespace std;
void Letters(int x,int y) {
	terminal_set("0x061: 1.png, size=16x16");
	terminal_printf(x + 0, y + 0, "a");
	terminal_set("0x062: 2.png, size=16x16");
	terminal_printf(x + 2, y + 0, "b");

	terminal_set("0x063: 3.png, size=16x16");
	terminal_printf(x + 4, y + 0, "c");
	terminal_set("0x064: 4.png, size=16x16");
	terminal_printf(x + 6, y + 0, "d");

	terminal_set("0x065: 5.png, size=16x16");
	terminal_printf(x + 8, y + 0, "e");
	terminal_set("0x066: 6.png, size=16x16");
	terminal_printf(x + 10, y + 0, "f");

	terminal_set("0x067: 7.png, size=16x16");
	terminal_printf(x + 12, y + 0, "g");
	terminal_set("0x068: 8.png, size=16x16");
	terminal_printf(x + 14, y + 0, "h");

	terminal_set("0x069: 9.png, size=16x16");
	terminal_printf(x + 16, y + 0, "i");
	terminal_set("0x06A: 10.png, size=16x16");
	terminal_printf(x + 18, y + 0, "j");
}
void getMap() {
	// левая
	terminal_set("0x02A: map.png, size=16x16");//*
	for (int i = 0; i < 10; i++) { // л
		terminal_printf(10, 4 + i , "*");
	}
	for (int i = 0; i < 12; i++) { // в 
		terminal_printf(10 + i*2, 3, "*");
	}
	for (int i = 0; i < 11; i++) { // н
		terminal_printf(10 + i*2, 14, "*");
	}
	for (int i = 0; i < 11; i++) { // п
		terminal_printf(32, 4 + i , "*");
	}
	// правая
	for (int i = 0; i < 10; i++) { // л
		terminal_printf(46, 4 + i, "*");
	}
	for (int i = 0; i < 12; i++) { // в 
		terminal_printf(46 + i * 2, 3, "*");
	}
	for (int i = 0; i < 11; i++) { // н
		terminal_printf(46 + i * 2, 14, "*");
	}
	for (int i = 0; i < 11; i++) { // п
		terminal_printf(68, 4 + i, "*");
	}
	Letters(12, 2);
	Letters(48, 2);
	const char* x = " 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 9\n10";
	terminal_printf(8, 4, x);
	terminal_printf(44, 4, x);
}