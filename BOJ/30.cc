#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	std::vector<int> vector;
	bool check = false; int sum = 0;
	std::string number;
	std::cin >> number;
	for (int num = 0; num < number.length(); num++) {
		if (number[num] == '0') check = true;
		sum += number[num] - '0';
		vector.push_back(number[num] - '0');
	}
	if (check && !(sum % 3)) {
		std::sort(vector.begin(), vector.end(), std::greater<int>());
		for (int num = 0; num < vector.size(); num++) std::cout << vector[num];
	}
	else std::cout << -1;
}