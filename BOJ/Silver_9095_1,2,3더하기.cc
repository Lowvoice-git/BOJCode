#include <iostream>

int main() {
	int n; std::cin >> n;
	int MEMO[11] = { 0,1,2,4 };
	while (n--) {
		int number; std::cin >> number;
		for (int num = 4; num <= number; num++)
			MEMO[num] = MEMO[num - 3] + MEMO[num - 2] + MEMO[num - 1];
		std::cout << MEMO[number] << '\n';
	}
}