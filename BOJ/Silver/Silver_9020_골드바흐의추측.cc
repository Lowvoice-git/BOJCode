#include <iostream>
#include <vector>

std::vector<bool> Prime_numbers(1000001, true);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	Prime_numbers[1] = false;
	for (int num = 2; num <= 1000000; num++) {
		int mult = 2;
		while (num * mult <= 1000000 && Prime_numbers[num] == true) {
			Prime_numbers[num * mult] = false; mult++;
		}
	}

	int N = 1;
	while (N) {
		std::cin >> N;
		if (N == 0) break;
		bool check = false;
		for (int P = 3; P < N; P += 2) {
			if (Prime_numbers[P] && Prime_numbers[N - P]) {
				std::cout << N << " = " << P << " + " << N - P << '\n';
				check = false;
				break;
			}
			else check = true;
		}
		if (check) std::cout << "Goldbach's conjecture is wrong.\n";
	}
}