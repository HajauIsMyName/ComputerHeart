#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int Time = 150;

void textColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

vector <string> input(char* s) {
	ifstream cin(s);
	vector <string> result;
	string x;

	while (1) {
		if (!getline(cin, x)) {
			return result;
		}

		result.push_back(x);
	}
}

void Computer(int x, int y, vector <string> computer) {
	int i;
	string s;

	for (i = 0; i < computer.size(); i++) {
		if (i == 8) {
			s = computer[i].substr(0, 20);
		}
		
		else {
			s = computer[i].substr(0, 25);
		}

		gotoXY(x, y + i);
		cout << s;
	}

	for (i = 0; i < computer.size(); i++) {
		if (i == 8) {
			s = " " + computer[i].substr(45);
		}
		
		else {
			s = computer[i].substr(43);
		}

		gotoXY(x + 44, y + i);
		cout << s;
	}

	for (i = 0; i <= 12; i++) {
		gotoXY(x + i + 21, y + 8);
		cout << computer[8][i + 21];

		gotoXY(x + 45 - i, y + 8);
		cout << computer[8][45 - i];

		Sleep(Time);
	}

	for (i = 0; i < 8; i++) {
		textColor(12);	

		gotoXY(x + 35 - i - 3, y + 8 - i);
		cout << computer[8 - i].substr(35 - i - 3, i * 2 + 3);
		
		if (i == 4) {
			textColor(7);

			gotoXY(x + 13, y + 5);
			cout << "___";

			Sleep(Time * 1.5);

			gotoXY(x + 12, y + 5);
			cout << "\\";

			gotoXY(x + 16, y + 5);
			cout << "/";
		}
		Sleep(Time * 1.5);
	}
}

void heart(int x, int y, vector<string> string0, vector<string> string1, vector<string> string2) {
	while (1) {
		textColor(7);
		gotoXY(x + 4 + 13, y + 30 + 3); cout << "v   v";

		for (int i = 0; i < string0.size(); i++) {
			gotoXY(x, y + i);
			cout << string0[i];
		}

		gotoXY(0, 0);
		Sleep(Time);

		for (int i = 20; i >= 5; i--) {
			for (int j = 17; j < 61; j++) {
				gotoXY(x + j, y + i);

				if (string1[i][j] == '*') {
					textColor(12);
				}
				
				else {
					textColor(7);
				}

				cout << string1[i][j];
			}

			gotoXY(0, 0);
			Sleep(Time);
		}

		Sleep(Time * 2);
		textColor(12);

		for (int i = 20; i >= 5; i--) {
			for (int j = 0; j < 61; j++) {
				if (string2[i][j] != '@' || (j > 30 && j < 47 && i <= 8)) {
					continue;
				}

				gotoXY(x + j, y + i);
				cout << string2[i][j];
			}

			Sleep(Time);
		}

		gotoXY(x + 22, y + 4);
		cout << "@@@@@@@@@@@";

		gotoXY(x + 44, y + 4);
		cout << "@@@@@@@@@@@";

		Sleep(Time);

		gotoXY(x + 31, y + 5);
		cout << "@@@@@";

		gotoXY(x + 41, y + 5);
		cout << "@@@@@";

		Sleep(Time);

		gotoXY(x + 35, y + 6);
		cout << "@@@";

		gotoXY(x + 39, y + 6);	
		cout << "@@@";

		Sleep(Time);

		gotoXY(x + 38, y + 7);	
		cout << "@";

		Sleep(Time);

		for (int i = 0; i < 4; i++) {
			for (int ii = 0; ii < 3; ii++) {
				textColor(12);

				gotoXY(x + 38, y + 8 + ii);
				cout << char(3);

				Sleep(Time * 2);

				textColor(7);

				gotoXY(x + 38, y + 8 + ii);
				cout << string2[8 + ii][38];
			}

			for (int j = 33; j < 44; j++) {
				if (string2[14 - i][j] == '3') {
					textColor(12);

					gotoXY(x + j, y + 14 - i);
					cout << char(3);
				}
			}

			Sleep(Time * 2);
		}

		gotoXY(x + 4 + 13, y + 30 + 3); cout << "0   0";
		Sleep(Time * 3);
	}
}

int main() {
	int x = 20, y = 2;

	char file1[] = "./file1.txt";
	char file2[] = "./file2.txt";
	char file3[] = "./file3.txt";
	char file4[] = "./file4.txt";

	vector<string> computer = input(file1);
	vector<string> s0 = input(file2);
	vector<string> s1 = input(file3);
	vector<string> s2 = input(file4);

	Computer(x + 5, y + 30, computer);
	heart(x, y, s0, s1, s2);
}