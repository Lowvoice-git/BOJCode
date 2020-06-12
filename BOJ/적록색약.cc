#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> direction = { {-1,0},{0,-1},{1,0},{0,1} };
int N; char grid[101][101];

int DFS(int Y, int X, int value, char key) {
	grid[Y][X] = value;

	for (int num = 0; num < 4; num++) {
		int ny = Y + direction[num].first;
		int nx = X + direction[num].second;

		if (ny >= 0 && nx >= 0 && ny < N && nx < N && grid[ny][nx] == key)
			DFS(ny, nx, value, key);
	}
	return 1;
}

int main() {
	std::cin >> N;
	int result[2] = { 0, };
	for (int Y = 0; Y < N; Y++)
		std::cin >> grid[Y];

	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			switch (grid[Y][X]) {
			case 'R': result[0] += DFS(Y, X, '1', 'R'); break;
			case 'G': result[0] += DFS(Y, X, '1', 'G'); break;
			case 'B': result[0] += DFS(Y, X, '2', 'B'); break;
			default: break;
			}
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			switch (grid[Y][X]) {
			case '1': result[1] += DFS(Y, X, '0', '1'); break;
			case '2': result[1] += DFS(Y, X, '0', '2'); break;
			default: break;
			}
	std::cout << result[0] << ' ' << result[1];
}