// BingoDay4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Board {
	int arr[25];

	union {
		bool pickedArr[25];
		bool pickedData[5][5] = { false };
	};
};

vector<Board> boards;
vector<int> picked;

void readInput() {
	ifstream in;
	int x;
	
	Board a_board;

	in.open("input.txt", ios::in); 

	string header;

	in >> header;

	stringstream ss(header);

	while (ss.good()) {
		getline(ss, header, ',');
		x = atoi(header.c_str());
		picked.push_back(x);
	}

	string data;
	int c = 0;

	while (!in.eof()) {
		in >> data;

		x = atoi(data.c_str());

		a_board.arr[c] = x;

		c++;
		if (c == 25) {
			c = 0;
			boards.push_back(a_board);
		}
	}

	in.close();
}

bool checkRow(Board a_board, int row) {

	for (auto i = 0; i < 5; i++) {
		if (!a_board.pickedData[row][i]) {
			return false;
		}
	}

	return true;
}

bool checkCol(Board a_board, int col) {

	for (auto i = 0; i < 5; i++) {
		if (!a_board.pickedData[i][col]) {
			return false;
		}
	}

	return true;
}

int sum(Board a_board) {
	int x = 0;

	for (auto i = 0; i < 25; i++) {
		if (!a_board.pickedArr[i]) {
			x += a_board.arr[i];
		}
	}

	return x;
}

int main()
{
	readInput();

	bool winner = false;
	int winNum = 0, lastNum = 0;
	Board winBoard, lastBoard;

	int numBoards = boards.size();

	bool* won = new bool[numBoards];

	for (auto i = 0; i < numBoards; i++) {
		won[i] = false;
	}

	for (auto& curNum : picked) {
		for (auto i = 0; i < 25; i++) {
			for (auto c = 0; auto & b : boards) {
				if (curNum == b.arr[i]) {
					b.pickedArr[i] = true;
					if (checkRow(b, i / 5) || checkCol(b,  i % 5)) {
						if (!winner) {
							winner = true;
							winNum = curNum;
							winBoard = b;
						}
						if (!won[c]) {
							lastNum = curNum;
							lastBoard = b;
							won[c] = true;
						}
					}
				}
				c++;
			}
		}
	}


	cout << "winning score is " << sum(winBoard) * winNum << endl;
	cout << "last    score is " << sum(lastBoard) * lastNum << endl;

}

