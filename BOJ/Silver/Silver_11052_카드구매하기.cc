#include <iostream>
#include <algorithm>

int cost[1001], memo[1001];

int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		std::cin >> cost[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			memo[i] = std::max(memo[i], memo[i - j] + cost[j]);

	std::cout << memo[N];
}