#include <iostream>
#include <vector>

std::vector<bool> Prime_numbers(246913, true);

int main() {
	Prime_numbers[1] = false;
	for (int num = 2; num <= 246912; num++) {
		int mult = 2;
		while (num * mult < 246913 && Prime_numbers[num]) {
			Prime_numbers[num * mult] = false; mult++;
		}
	}
	int N, count = 0; scanf("%d", &N);
	while (N) {
		for (int num = N + 1; num <= 2 * N; num++) {
			if (Prime_numbers[num]) count++;
		}
		printf("%d\n", count); count = 0;
		scanf("%d", &N);
	}
}