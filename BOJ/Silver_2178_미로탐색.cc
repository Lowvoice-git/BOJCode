#include <iostream>
#include <utility>
#include <queue>

int N, M;
bool matrix[101][101];
bool visit[101][101];
std::vector<std::vector<int>> direction = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };

int BFS() {
	std::queue<std::pair<std::pair<int, int>, int>> Queue;
	Queue.push(std::make_pair(std::make_pair(0, 0), 1));
	visit[0][0] = true;

	while (!Queue.empty()) {
		int x = Queue.front().first.second;
		int y = Queue.front().first.first;
		int z = Queue.front().second;

		Queue.pop();

		if (x == M - 1 && y == N - 1) return z;

		for (int num = 0; num < 4; num++) {
			int nx = x + direction[num][0];
			int ny = y + direction[num][1];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visit[ny][nx])
				continue;
			if (!matrix[ny][nx])
				continue;

			Queue.push(std::make_pair(std::make_pair(ny, nx), z + 1));
			visit[ny][nx] = true;
		}
	}
}

int main() {
	std::cin >> N >> M;
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < M; X++) {
			char temp; std::cin >> temp;
			matrix[Y][X] = temp - '0';
		}
	}

	std::cout << BFS();
}