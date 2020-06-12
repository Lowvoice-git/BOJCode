#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> Prime_numbers(10001, true);

int main() {
	Prime_numbers[1] = false;
	for (int num = 2; num <= 10000; num++) {
		int mult = 2;
		while (num * mult <= 10000 && Prime_numbers[num]) {
			Prime_numbers[num * mult] = false; mult++;
		}
	}
	int N; scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		int number, save = 10000, count = 1, result; scanf("%d", &number);
		while (count++) {
			if (count > number) break;
			if (Prime_numbers[count]) {
				if (Prime_numbers[number - count]) {
					if (abs(number - (2 * count)) < save) {
						save = number - (2 * count); result = count;
					}
				}
			}
		}
		printf("%d %d\n", result, number - result);
	}
}