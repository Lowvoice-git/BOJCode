#include <iostream>
#include <algorithm>

int temp[1001];
int DP[2][1001][32];

int main() {
	int T, W, result = 0;
	std::cin >> T >> W;
	for (int t = 1; t <= T; t++)
		std::cin >> temp[t];

	for (int t = 1; t <= T; t++) {
		for (int w = 1; w <= W + 1; w++) {
			if (temp[t] == 1) {
				DP[0][t][w] = std::max(DP[0][t - 1][w] + 1, DP[1][t - 1][w - 1] + 1);
				DP[1][t][w] = std::max(DP[0][t - 1][w - 1], DP[1][t - 1][w]);
			}
			else {
                if (t == 1 && w == 1)continue;
				DP[0][t][w] = std::max(DP[0][t - 1][w], DP[1][t - 1][w - 1]);
				DP[1][t][w] = std::max(DP[0][t - 1][w - 1] + 1, DP[1][t - 1][w] + 1);
			}
		}
	}

	for (int w = 1; w <= W + 1; w++)
		result = std::max(result,std::max(DP[0][T][w], DP[1][T][w]));

	std::cout << result;
}