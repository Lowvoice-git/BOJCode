#include <iostream>
#include <algorithm>
#include <vector>

int memo[1001][3];
std::vector<std::vector<int>> cost;

int main() {
	int N; std::cin >> N;
	for (int num = 0; num < N; num++) {
		int R, G, B;
		std::cin >> R >> G >> B;
		cost.push_back({ R,G,B });
	}

	for (int num = 1; num <= N; num++) {
		memo[num][0] = std::min(memo[num - 1][1], memo[num - 1][2]) + cost[num - 1][0];
		memo[num][1] = std::min(memo[num - 1][0], memo[num - 1][2]) + cost[num - 1][1];
		memo[num][2] = std::min(memo[num - 1][0], memo[num - 1][1]) + cost[num - 1][2];
	}

	std::cout << std::min(std::min(memo[N][0], memo[N][1]), memo[N][2]);
}