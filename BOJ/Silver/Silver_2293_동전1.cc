#include <iostream>

int memo[10001];
int cost[101];

int main() {
	int N, K; memo[0] = 1;
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
		std::cin >> cost[i];

	for (int i = 1; i <= N; i++)
		for (int j = cost[i]; j <= K; j++)
			if (cost[i] <= j)
				memo[j] += memo[j - cost[i]];

	std::cout << memo[K];
}