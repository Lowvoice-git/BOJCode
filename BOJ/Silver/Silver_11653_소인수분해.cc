#include <iostream>
#include <vector>

std::vector<bool> Prime_numbers(10000001, true);

int main() {
	Prime_numbers[1] = false;
	int N, index = 2;
	std::cin >> N;
	for (int num = 2; num <= N; num++) {
		int mult = 2;
		while (num * mult <= N && Prime_numbers[num] == true) {
			Prime_numbers[num * mult] = false; mult++;
		}
	}

	while (N != 1) {
		if (Prime_numbers[index]) {
			if (N % index == 0) {
				N /= index;
				std::cout << index << '\n';
			}
			else index++;
		}
		else index++;
	}
}