#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int main(void) {
	std::string number;
	int number_pack[10] = { 0, }, count = 1;
	std::cin >> number;
	std::sort(number.begin(), number.end());
	for (int num = 0; num < number.length(); num++) {
		int temp = number[num];
		if (temp == number[num])
			number_pack[temp - '0']++;
	}
	int temp = number_pack[6] + number_pack[9];
	if (temp % 2 == 1) {
		number_pack[6] = (temp / 2) + 1;
		number_pack[9] = temp / 2;
	}
	else number_pack[6] = number_pack[9] = temp / 2;
	std::sort(number_pack, number_pack + 10, std::greater<int>());
	printf("%d", number_pack[0]);
	return 0;
}