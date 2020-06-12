#include <iostream>
#include <vector>

int main() {
	std::vector<bool> prime_numbers(1001, true); prime_numbers[1] = false;
	for (int num = 2; num < 1001; num++) {
		int mult = 2;
		while (num * mult < 1001 && prime_numbers[num] == 1) {
			prime_numbers[num * mult] = 0; mult++;
		}
	}
	int N, count = 0;
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		int number; scanf("%d", &number);
		if (prime_numbers[number]) count++;
	}
	printf("%d", count);
}