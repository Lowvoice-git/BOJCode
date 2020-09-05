#include <iostream>
#include <algorithm>

int memo[2][1000001];
int Array[1000001];

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> Array[i];

	int result = Array[0];

	for (int i = 0; i < N; i++) {
		memo[0][i] = memo[1][i] = Array[i];
		if (i == 0) continue;
		memo[0][i] = std::max(memo[0][i - 1] + Array[i], Array[i]);
		memo[1][i] = std::max(memo[1][i - 1] + Array[i], memo[0][i - 1]);

		result = std::max(result, std::max(memo[0][i], memo[1][i]));
	}

	std::cout << result;
}