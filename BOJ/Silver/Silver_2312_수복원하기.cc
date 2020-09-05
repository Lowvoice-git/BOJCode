#include <iostream>
#include <vector>

std::vector<bool> Prime_numbers(100001, true);

int main() {
	Prime_numbers[1] = false;
	for (int num = 2; num <= 100000; num++) {
		int mult = 2;
		while (num * mult <= 100000 && Prime_numbers[num]) {
			Prime_numbers[num * mult] = false; mult++;
		}
	}
	int N; scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		int number, prime_num, count = 0; scanf("%d", &number); int copy_value = number;
		for (prime_num = 2; prime_num <= number; prime_num++) {
			while (Prime_numbers[prime_num]) {
				if (copy_value%prime_num) break;
				else {
					copy_value /= prime_num;
					count++; 
				}
			}
			if (count) printf("%d %d\n", prime_num, count);
			count = 0;
		}
	}
}