#include <iostream>
#include <algorithm>

int memo[2][100001], Array[2][100001];

int main() {
	int index, N;
	std::cin >> N;
	while (N-- > 0) {
		std::cin >> index;
		for (int num1 = 0; num1 <= 1; num1++)
			for (int num2 = 1; num2 <= index; num2++)
				std::cin >> Array[num1][num2];
		memo[0][0] = memo[1][0] = 0;
		memo[0][1] = Array[0][1];	memo[1][1] = Array[1][1];
		for (int num1 = 2; num1 <= index; num1++) {
			memo[0][num1] = std::max(memo[1][num1 - 1], memo[1][num1 - 2]) + Array[0][num1];
			memo[1][num1] = std::max(memo[0][num1 - 1], memo[0][num1 - 2]) + Array[1][num1];
		}
		printf("%d\n", std::max(memo[0][index], memo[1][index]));
	}
}