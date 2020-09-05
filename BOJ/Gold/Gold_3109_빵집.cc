#include <iostream>

int N, M, count;
char matrix[10001][501];
bool visited[10001][501];

int direction[3][2] = { {-1,1},{0,1},{1,1} };

bool check(int Y, int X) {
	return (Y >= 1 && Y <= N) && (X >= 1 && X <= M) && (visited[Y][X] == false && matrix[Y][X] == '.');
}

bool DFS(int Y, int X) {
	visited[Y][X] = true;

	if (X == M) {
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int ny = Y + direction[i][0];
		int nx = X + direction[i][1];

		if (check(ny, nx)) {
			bool flag = DFS(ny, nx);
			if (flag) return flag;
		}
	}

	return false;
}

int main() {
	int count = 0;
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			std::cin >> matrix[i][j];

	for (int i = 1; i <= N; i++)
		count += DFS(i, 1);

	std::cout << count;
}