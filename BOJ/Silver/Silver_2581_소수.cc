#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, M, sum = 0, min = 10001, count = 0;
	std::cin >> N >> M;
	std::vector<bool> prime_numbers(M + 1, true); prime_numbers[1] = false;
	for (int num = 2; num < M + 1; num++) {
		int mult = 2;
		while (num * mult < M + 1 && prime_numbers[num] == 1) {
			prime_numbers[num * mult] = 0; mult++;
		}
	}
	for (int num = N; num <= M; num++) {
		if (prime_numbers[num]) {
			sum += num;
			min = std::min(min, num);
		}

	}
	if (sum == 0) std::cout << "-1";
	else std::cout << sum << '\n' << min;
}