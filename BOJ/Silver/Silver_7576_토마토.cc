#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int N, M;
int matrix[1001][1001];
int visit[1001][1001];
std::vector<std::pair<int, int>> direction = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };

int main() {
	int result = 0;
	std::cin >> M >> N;
	std::queue<std::pair<int,int>> Queue;
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < M; X++) {
			int temp; std::cin >> temp;
			matrix[Y][X] = temp;
			visit[Y][X] = -1;
			if (matrix[Y][X] == 1) {
				Queue.push(std::make_pair(Y, X));
				visit[Y][X] = 0;
			}
		}
	}
	while (!Queue.empty()) {
		int y = Queue.front().first;
		int x = Queue.front().second;
		Queue.pop();

		for (int num = 0; num < 4; num++) {
			int nx = x + direction[num].first;
			int ny = y + direction[num].second;
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (matrix[ny][nx] == 0 && visit[ny][nx] == -1) {
					visit[ny][nx] = visit[y][x] + 1;
					Queue.push(std::make_pair(ny, nx));
				}
			}
		}
	}
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < M; X++)
			result = std::max(result, visit[Y][X]);
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < M; X++)
			if (matrix[Y][X] == 0 && visit[Y][X] == -1)
				result = -1;

	std::cout << result;
}