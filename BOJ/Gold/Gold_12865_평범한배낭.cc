#include <iostream>
#include <vector>
#include <algorithm>

int memo[101][100001];
std::vector<int> V, W;

int main() {
	int N, K, result = 0; std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int A, B; std::cin >> A >> B;
		V.push_back(B); W.push_back(A);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++) {
			if (W[i - 1] <= j)
				memo[i][j] = std::max(V[i - 1] + memo[i - 1][j - W[i - 1]], memo[i - 1][j]);
			else
				memo[i][j] = memo[i - 1][j];
			result = std::max(result, memo[i][j]);
		}

	std::cout << result;
}