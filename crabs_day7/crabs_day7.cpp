// crabs_day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int returnFuel(int position, int target) {
	int factor = 0;
	int sign = position > target ? 1 : -1;

	int sum = 0;

	while (target != position) {
		sum += 1 + factor;
		target += 1 * sign;
		factor++;
	}

	return sum;
}


int main()
{
	ifstream in;
	vector<int> crabs;

	in.open("input.txt", ios::in);

	string data;

	in >> data;

	stringstream ss(data);

	while (ss.good()) {
		getline(ss, data, ',');
		crabs.push_back(stoi(data));
	}

	in.close();

	int max = *max_element(crabs.begin(), crabs.end());
	int min = *min_element(crabs.begin(), crabs.end());

	int curMin = min;
	int curMinSum = -1;
	int sum;
	for (int i = min; i <= max; i++) {
		sum = 0;

		for (auto& c : crabs) {
			sum += returnFuel(c, i);
		}
		 
		if ((sum < curMinSum) || (curMinSum == -1)) {
			curMinSum = sum;
			curMin = i;
		}
	}

	cout << "Min Fuel is " << curMinSum << " for pos " << curMin << endl;

}
