#include <iostream>
#include <algorithm>

int N, M;
// 빙산의 개수가 10이하이기 때문에 300X300배열을 10개를 생성
// 0의 갯수로 뺏을 때 그래프가 변경이 되어서 2차원 배열이 아닌 3차원 배열로 구현했습니다.
int matrix[301][301];
// 깊이 우선 탐색을 위해 각 깊이에 따라 방문을 한지 안한지를 저장하는 배열
int discount[301][301];
int visited[301][301];

int direction[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

// 탐색을 할 때 문제의 2차원 배열 범위을 넘었는지 안넘었는지를 검사하는 함수
bool check(int Y, int X) {
	return (0 <= Y && N > Y) && (0 <= X && M > X);
}

int DFS(int Y, int X, int depth) {
	int count = 0;
	// 상하좌우에 0이 얼마나 있는지 저장하는 변수
	visited[Y][X] = depth;

	for (int i = 0; i < 4; i++) {
		int ny = Y + direction[i][0];
		int nx = X + direction[i][1];

		// 만약 이전 그래프의 상하좌우에 0이 있으면 count변수를 1증가
		if (matrix[ny][nx] == 0)
			count++;
		// 범위를 넘지 않고 방문을 하지 않았으면 방문
		else if (check(ny, nx) && visited[ny][nx] != depth) {
			DFS(ny, nx, depth);
		}
	}

	discount[Y][X] = count;

	// 빙산의 개수를 반환
	return 1;
}

int main() {
	int depth = 0;
	// 만약 빙산이 1개일 경우 0을 출력해야 하기 때문에 boolean값으로 확인 할 수 있게 선언된 변수
	bool check = true;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			std::cin >> matrix[i][j];

	while (++depth) {
		int count = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				// 0이 아니고 이전에 방문했는지 검사하는 조건문
				if (matrix[i][j] > 0 && visited[i][j] == depth - 1)
					// 빙산의 개수를 count에 저장
					count += DFS(i, j, depth);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				// 빙산의 높이가 count를 뺏을 때 음수가 되면 0으로 저장
				if (matrix[i][j] - discount[i][j] < 0)
					matrix[i][j] = 0;
				// 빙산의 높이에 count를 뺀 값을 저장
				else matrix[i][j] = matrix[i][j] - discount[i][j];

				discount[i][j] = 0;
			}

		// 만약 빙산이 녹아 2로 나눠졌을 경우 반복문을 탈출하려고 선언한 조건문입니다.
		if (count > 1) {
			check = false;
			break;
		}
		else if (count == 0) break;
	}

	// 섬이 녹으면서 2로 나눠지지 않았으면 0을 출력
	if (check) std::cout << 0;
	// 섬이 녹아서 2로 나눠졌으면 얼마나 걸렸는지를 출력
	else std::cout << depth - 1;
}