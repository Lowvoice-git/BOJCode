#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, max,sum = 0;
	std::cin >> N >> max;
	std::vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		std::cin >> sequence[i];
	for (int i = 0; i < N - 2; i++)
		for (int j = 1+i; j < N - 1; j++)
			for (int k = 1+j; k < N; k++)
				if (sequence[i] + sequence[j] + sequence[k] <= max)
					sum = std::max(sequence[i] + sequence[j] + sequence[k], sum);
	std::cout << sum;
}