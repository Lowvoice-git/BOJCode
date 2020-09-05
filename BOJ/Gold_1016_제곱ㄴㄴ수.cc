#include <iostream> 

bool check[1000001];

int main() {
	long long min, max;
	std::cin >> min >> max;

	for (long long i = 2; i * i <= max; i++) {
		long long start = min / (i * i);
		if (start * i * i != min) start++;

		for (long long j = start; i * i * j <= max; j++)
			check[i * i * j - min] = true;
	}

	int count = 0;

	for (int i = 0; i < max - min + 1; i++)
		if (!check[i]) count++;

	std::cout << count;
}