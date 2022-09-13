// Venture_Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

regex rx("(\\d+),(\\d+) -> (\\d+),(\\d+)");

struct vec2 {
	pair<int, int> cord;
};

int main()
{
	ifstream in;

	in.open("input.txt", ios::in);

	string data;
	pair<vec2, vec2> line;
	int maxX = 0;
	int maxY = 0;
	vector<pair<vec2, vec2> > lines;

	while (getline(in, data)) {

		smatch sm;
		if (regex_search(data, sm, rx)) {
			line.first.cord = make_pair(stoi(sm[1].str()), stoi(sm[2].str()));
			line.second.cord   = make_pair(stoi(sm[3].str()), stoi(sm[4].str()));
			if (max(line.first.cord.first, line.second.cord.first) > maxX) {
				maxX = max(line.first.cord.first, line.second.cord.first);
			}
			if (max(line.first.cord.second, line.second.cord.second) > maxX) {
				maxY = max(line.first.cord.second, line.second.cord.second);
			}
			lines.push_back(line);
		}
	}

	in.close();

	vector<vector<int> > grid_p1(maxX + 1, vector<int>(maxY + 1, 0));
	vector<vector<int> > grid_p2(maxX + 1, vector<int>(maxY + 1, 0));


	for (auto& l : lines) {
		int x1 = l.first.cord.first;
		int y1 = l.first.cord.second;
		int x2 = l.second.cord.first;
		int y2 = l.second.cord.second;
		if (l.first.cord.first == l.second.cord.first) {
			int i = l.first.cord.first;
			int start = min(l.first.cord.second, l.second.cord.second);
			int end = max(l.first.cord.second, l.second.cord.second);
			for (int j = start; j <= end; j++) {
				grid_p1[i][j] += 1;
				grid_p2[i][j] += 1;
			}
		}
		else if (l.first.cord.second == l.second.cord.second) {
			int j = l.first.cord.second;
			int start = min(l.first.cord.first, l.second.cord.first);
			int end = max(l.first.cord.first, l.second.cord.first);
			for (int i = start; i <= end; i++) {
				grid_p1[i][j] += 1;
				grid_p2[i][j] += 1;
			}
		}
		else {
			bool dirx = x1 < x2 ? true : false;
			bool diry = y1 < y2 ? true : false;

			int i = x1;
			int j = y1;
			while (i != x2) {
				grid_p2[i][j] += 1;
				i += dirx ? 1 : -1;
				j += diry ? 1 : -1;
			}
			grid_p2[i][j] += 1;

		}
	}


	int sum = 0;
	for (auto& g : grid_p1) {
		for (auto& e : g) {
			if (e > 1) {
				sum += 1;
			}
		}
	}

	cout << "num overlap p1 = " << sum << endl;

	sum = 0;
	for (auto& g : grid_p2) {
		for (auto& e : g) {
			if (e > 1) {
				sum += 1;
			}
		}
	}
	cout << "num overlap p2 = " << sum << endl;


}

