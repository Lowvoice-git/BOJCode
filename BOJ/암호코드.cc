#include <iostream>
#include <string>
#include <vector>

int DP[5010];

int main() {
	std::string number;
	std::cin >> number;

	if (number == "0") { std::cout << 0; return 0; }

	std::vector<int> element(number.length() + 1);
	for (int num = 1; num <= number.length(); num++)
		element[num] = number[num - 1] - '0';

	DP[0] = 1;

	for (int num = 1; num <= number.length(); num++) {
		if (element[num] > 0 && element[num] < 10)
			DP[num] = (DP[num] + DP[num - 1]) % 1000000;

		if (num != 1) {
			int temp = (element[num - 1]) * 10 + element[num];
			if (temp > 9 && temp < 27)
				DP[num] = (DP[num] + DP[num - 2]) % 1000000;
		}
	}

	std::cout << DP[number.length()];
}