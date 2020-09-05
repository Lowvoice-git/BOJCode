#include <iostream>
#include <algorithm>

int memo[501][502];

int main() {
	int N, max = -1;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			std::cin >> memo[i][j];

	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (j == 1)memo[i][j] += memo[i - 1][j];
			else if (j == N)memo[i][j] += memo[i - 1][j - 1];
			else memo[i][j] += std::max(memo[i - 1][j], memo[i - 1][j - 1]);

	for (int i = 1; i <= N; i++)
		max = std::max(max, memo[N][i]);

	std::cout << max;
}