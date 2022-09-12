// SonarSweep1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream in;

	in.open("input.txt", std::ios::in);

	std::vector<int> data;

	int i = 0;
	int x = 0;
	int count = 0;
	int sumCount = 0;
	int size = 0;
	int prevSum = 0, curSum = 0;

	while (!in.eof()) {
		in >> x;
		data.push_back(x);
	}

	in.close();

	size = data.size() - 1;

	for (std::size_t i = 0;  auto & d : data) {
		if (i == 0) {
			x = d;
			if (!(size - 2 < i)) {
				prevSum = d + data[i + 1] + data[i + 2];
			}
			i++;
			continue;
		}

		if (d > x) {
			count++;
		}

		if (!(size - 2 < i)) {
			curSum = d + data[i + 1] + data[i + 2];
			if (curSum > prevSum) {
				sumCount++;
			}

			prevSum = curSum;
		}
		
		i++;
		x = d;
	}

	std::cout << "P1 Answer is " << count << std::endl;
	std::cout << "P2 Answer is " << sumCount << std::endl;



}

