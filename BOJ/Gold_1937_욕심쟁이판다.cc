#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int N;
int DP[500][500];
int matrix[500][500];
std::pair<int, int> direction[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int DFS(int Y, int X) {
	if (DP[Y][X]) return DP[Y][X];
	DP[Y][X] = 1;
	for (int num = 0; num < 4; num++) {
		if (Y + direction[num].first < 0 || X + direction[num].second < 0 || Y + direction[num].first >= N || X + direction[num].second >= N)
			continue;
		if (matrix[Y][X] < matrix[Y + direction[num].first][X + direction[num].second]) {
			DP[Y][X] = std::max(DP[Y][X], DFS(Y + direction[num].first, X + direction[num].second) + 1);
		}
	}
	return DP[Y][X];
}

int main() {
	std::cin >> N;
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			std::cin >> matrix[Y][X];

	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			DFS(Y, X);

	int result = 0;
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			result = std::max(result, DP[Y][X]);

	std::cout << result;
}