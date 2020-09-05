#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
	int N, K; std::cin >> N >> K;
	std::vector<unsigned int> Coin(N);
	std::vector<unsigned int> memo(K + 1, INT_MAX);
	memo[0] = 0;

	for (int num = 0; num < N; num++)
		std::cin >> Coin[num];

	for (int i = 0; i < N; i++)
		for (int j = Coin[i]; j <= K; j++)
			memo[j] = std::min(memo[j], memo[j - Coin[i]] + 1);

	if (memo[K] == INT_MAX)std::cout << -1;
	else std::cout << memo[K];
}