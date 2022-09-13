// lanternfish_day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ifstream in;
	vector<int> fish;
	deque<uint64_t> lifecycle;

	in.open("input.txt", ios::in);

	string data;

	in >> data;

	stringstream ss(data);

	while (ss.good()) {
		getline(ss, data, ',');
		fish.push_back(stoi(data));
	}

	int days;

	cout << "how many days?" << endl;
	cin >> days;

	auto curSize = fish.size();

	cout << "Initial State: ";

	for (auto& f : fish) {
		cout << f << ",";
	}

	cout << endl;

	lifecycle.push_back(0);
	
	for (uint64_t i = 1; i <= 6; i++) {
		lifecycle.push_back(count(fish.begin(), fish.end(), i));
	}

	lifecycle.push_back(0);
	lifecycle.push_back(0);


	while (days != 0) {
		days--;

		uint64_t f = lifecycle.front();
		lifecycle.pop_front();

		lifecycle[6] += f;
		lifecycle.push_back(f);
	}

	uint64_t sum = 0;

	for (auto& l : lifecycle) {
		sum += l;
	}

	cout << "Number of Fish = " << sum << endl;

}

