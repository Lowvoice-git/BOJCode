#include <iostream>
#include <algorithm>

char matrix[21][21];
bool visited[21][21];
bool alphabetVisited[26];
int R, C, result = 1;
int direction[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

void DFS(int Y,int X, int count) {
	if (visited[Y][X]) return;
	else {
		if (matrix[Y][X] - 'A' >= 0)
			if (!alphabetVisited[matrix[Y][X] - 'A']) {
				alphabetVisited[matrix[Y][X] - 'A'] = true;
				count++;
			}
			else return;
		for (int i = 0; i < 4; i++) {
			int nx = X + direction[i][1];
			int ny = Y + direction[i][0];

			if (nx <= C && ny <= R && nx > 0 && ny > 0 && alphabetVisited[matrix[ny][nx] - 'A'] == false) {
				visited[Y][X] = true;
				result = std::max(result, count);
				DFS(ny, nx, count);
				alphabetVisited[matrix[ny][nx] - 'A'] = visited[Y][X] = false;
			}
		}
	}
}

int main() {
	std::cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			std::cin >> matrix[i][j];

	DFS(1, 1, 1);

	std::cout << result;
}