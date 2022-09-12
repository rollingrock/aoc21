// Dive_day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Vec2 {
	int hor;
	int dep;
	int aim;
};

int main()
{
	ifstream in;
	Vec2 pos = {0, 0, 0};
	string cmd;
	int data;


	in.open("input.txt", ios::in);


	while (!in.eof()) {
		in >> cmd >> data;

		if (!(cmd.compare("forward"))) {
			pos.hor += data;
		}
		else if (!(cmd.compare("up"))) {
			pos.dep -= data;
		}
		else if (!(cmd.compare("down"))) {
			pos.dep += data;
		}
	}

	in.close();


	cout << "part1" << endl;
	cout << "Position = " << pos.hor << " : " << pos.dep << endl;
	cout << "mult = " << pos.hor * pos.dep << endl;

	in.open("input.txt", ios::in);
	pos = { 0,0,0 };


	while (!in.eof()) {
		in >> cmd >> data;

		if (!(cmd.compare("forward"))) {
			pos.hor += data;
			pos.dep += pos.aim * data;
		}
		else if (!(cmd.compare("up"))) {
			pos.aim -= data;
		}
		else if (!(cmd.compare("down"))) {
			pos.aim += data;
		}
	}

	in.close();

	cout << "part2" << endl;
	cout << "Position = " << pos.hor << " : " << pos.dep << endl;
	cout << "mult = " << pos.hor * pos.dep << endl;
}

