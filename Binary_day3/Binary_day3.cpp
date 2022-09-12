// Binary_day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int findMatch(vector<string> list, bool dir, int searchLen) {
	int x = 0;
	auto len = list[0].length();
	vector<string> newList;

	if (list.size() == 1) {
		string s = list[0];

		for (auto i = 0; i < len; i++) {
			int t = s[i];
			x += (t - 48) << (len - i - 1);
		}

		std::cout << s << endl;
		return x;
	}

	int* tracker = new int[len];

	for (auto i = 0; i < len; i++) {
		tracker[i] = 0;
	}

	for (auto& l : list) {
		for (auto i = 0; i < len; i++) {
			x = l[i];
			tracker[i] += x - 48 > 0 ? 1 : -1;
		}
	}
	string searchString;

	for (auto i = 0; i < searchLen; i++) {
		if (tracker[i] >= 0) {
			searchString += dir ? "1" : "0";
		}
		else {
			searchString += dir ? "0" : "1";
		}
	}

	char sc = searchString[searchLen-1];

	for (auto& l : list) {
		char c = l[searchLen-1];

		if (c == sc) {
			newList.push_back(l);
		}
	}

	if (newList.size() == 0) {
		cout << "didn't find match" << endl;
		return 0;
	}
	else {
		return findMatch(newList, dir, searchLen + 1);
	}

}

int main()
{
	ifstream in;
	string data;
	int x;
	size_t len;
	vector<string> diags;

	in.open("input.txt", ios::in);
	
	in >> data;
	len = data.length();
	int* tracker = new int[len];

	for (auto i = 0; i < len; i++) {
		tracker[i] = 0;
	}

	cout << data << " " << len << endl;

	in.seekg(0, ios::beg);

	while (!in.eof()) {
		in >> data;
		diags.push_back(data);

		for (auto i = 0; i < len; i++) {
			x = data[i];
			tracker[i] += x - 48 > 0 ? 1 : -1;
		}
	}

	in.close();
	int gm = 0, ep = 0;
	string gamma, epsilon;

	for (auto i = 0; i < len; i++) {
		if (tracker[i] > 0) {
			gm += 1 << (len - i - 1);
			gamma += "1";
			epsilon += "0";
		}
		else {
			ep += 1 << (len - i - 1);
			gamma += "0";
			epsilon += "1";
		}
	}
	 
	cout << "gamma   = " << gamma << " " << gm << endl;
	cout << "epsilon = " << epsilon << " " << ep << endl;
	cout << "power   = " << gm * ep << endl;

	gm = findMatch(diags, true, 1);
	ep = findMatch(diags, false, 1);

	cout << "oxy     = " << gm << endl;
	cout << "co2     = " << ep << endl;
	cout << "lifesup = " << gm * ep << endl;
}
