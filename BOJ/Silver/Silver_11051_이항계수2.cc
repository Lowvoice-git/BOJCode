#include <iostream>

int memo[1001][1001];

int main() {
	int N, K;
	std::cin >> N >> K;
	
	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= N; k++)
			if (n == k || k == 0) memo[n][k] = 1;
			else memo[n][k] = (memo[n - 1][k - 1] + memo[n - 1][k]) % 10007;

	std::cout << memo[N][K];
}