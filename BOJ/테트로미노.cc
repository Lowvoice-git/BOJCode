#include <iostream>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> PAIR;

bool visit[501][501];
int map[501][501];
int N, M;
PAIR direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int DFS(PAIR D, int level) {
	int result = 0;

	if (level == 4) return map[D.first][D.second];

	for (int num = 0; num < 4; num++) {
		PAIR temp = std::make_pair(D.first + direction[num].first, D.second + direction[num].second);
		if (0 <= temp.first && temp.first < N && 0 <= temp.second && temp.second < M && !visit[temp.first][temp.second]) {
			visit[temp.first][temp.second] = true;
			result = std::max(result, map[D.first][D.second] + DFS(temp, level + 1));
			visit[temp.first][temp.second] = false;
		}
	}

	return result;
}

int T_type(PAIR D) {
	int result = 0;
	if (D.first >= 1 && D.second >= 1 && D.second < M - 1)
		result = std::max(result, map[D.first][D.second - 1] + map[D.first][D.second] + map[D.first - 1][D.second] + map[D.first][D.second + 1]);
	if (D.first >= 1 && D.first < N - 1 && D.second < M - 1)
		result = std::max(result, map[D.first - 1][D.second] + map[D.first][D.second] + map[D.first][D.second + 1] + map[D.first + 1][D.second]);
	if (D.first >= 0 && D.first < N - 1 && D.second < M - 1)
		result = std::max(result, map[D.first][D.second - 1] + map[D.first][D.second] + map[D.first + 1][D.second] + map[D.first][D.second + 1]);
	if (D.first >= 1 && D.first <= N - 1 && D.second >= 1)
		result = std::max(result, map[D.first - 1][D.second] + map[D.first][D.second] + map[D.first][D.second - 1] + map[D.first + 1][D.second]);
	return result;
}

int main() {
	int result = 0;
	std::cin >> N >> M;

	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < M; X++)
			std::cin >> map[Y][X];

	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < M; X++) {
			visit[Y][X] = true;
			result = std::max(result, DFS({ Y,X }, 1));
			result = std::max(result, T_type({ Y,X }));
			visit[Y][X] = false;
		}

	std::cout << result;
}