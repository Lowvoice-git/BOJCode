#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

typedef std::vector<std::vector<int>> VV;

int N, max = 0;
VV map(20,std::vector<int>(20));

VV up(VV matrix) {
	for (int X = 0; X < N; X++) {
		int index = 0;
		std::queue<int> Queue;
		std::vector<bool> check(N, true);
		for (int Y = 0; Y < N; Y++) {
			if (matrix[Y][X] != 0) {
				Queue.push(matrix[Y][X]);
				matrix[Y][X] = 0;
			}
		}
		while (!Queue.empty()) {
			if (index > 0) {
				if (matrix[index - 1][X] == Queue.front() && check[index - 1]) {
					matrix[index - 1][X] += Queue.front();
					max = std::max(max, matrix[index - 1][X]);
					check[index - 1] = false;
					Queue.pop();
					continue;
				}
			}
			matrix[index][X] = Queue.front();
			Queue.pop();
			index++;
		}
	}
	return matrix;
}
VV down(VV matrix) {
	for (int X = 0; X < N; X++) {
		int index = N - 1;
		std::queue<int> Queue;
		std::vector<bool> check(N, true);
		for (int Y = N - 1; Y >= 0; Y--) {
			if (matrix[Y][X] != 0) {
				Queue.push(matrix[Y][X]);
				matrix[Y][X] = 0;
			}
		}
		while (!Queue.empty()) {
			if (index < N - 1) {
				if (matrix[index + 1][X] == Queue.front() && check[index + 1]) {
					matrix[index + 1][X] += Queue.front();
					max = std::max(max, matrix[index + 1][X]);
					check[index + 1] = false;
					Queue.pop();
					continue;
				}
			}
			matrix[index][X] = Queue.front();
			Queue.pop();
			index--;
		}
	}
	return matrix;
}
VV left(VV matrix) {
	for (int Y = 0; Y < N; Y++) {
		int index = 0;
		std::queue<int> Queue;
		std::vector<bool> check(N, true);
		for (int X = 0; X < N; X++) {
			if (matrix[Y][X] != 0) {
				Queue.push(matrix[Y][X]);
				matrix[Y][X] = 0;
			}
		}
		while (!Queue.empty()) {
			if (index > 0) {
				if (matrix[Y][index - 1] == Queue.front() && check[index - 1]) {
					matrix[Y][index - 1] += Queue.front();
					max = std::max(max, matrix[Y][index - 1]);
					check[index - 1] = false;
					Queue.pop();
					continue;
				}
			}
			matrix[Y][index] = Queue.front();
			Queue.pop();
			index++;
		}
	}
	return matrix;
}
VV right(VV matrix) {
	for (int Y = 0; Y < N; Y++) {
		int index = N - 1;
		std::queue<int> Queue;
		std::vector<bool> check(N, true);
		for (int X = N - 1; X >= 0; X--) {
			if (matrix[Y][X] != 0) {
				Queue.push(matrix[Y][X]);
				matrix[Y][X] = 0;
			}
		}
		while (!Queue.empty()) {
			if (index < N - 1) {
				if (matrix[Y][index + 1] == Queue.front() && check[index + 1]) {
					matrix[Y][index + 1] += Queue.front();
					max = std::max(max, matrix[Y][index + 1]);
					check[index + 1] = false;
					Queue.pop();
					continue;
				}
			}
			matrix[Y][index] = Queue.front();
			Queue.pop();
			index--;
		}
	}
	return matrix;
}

void DFS(VV matrix, int level) {
	if (level == 5) return;
	VV temp; int max = 0;
	for (int num = 1; num <= 4; num++) {
		switch (num) {
		case UP: DFS(up(matrix), level + 1); break;
		case DOWN: DFS(down(matrix), level + 1); break;
		case LEFT: DFS(left(matrix), level + 1); break;
		case RIGHT: DFS(right(matrix), level + 1); break;
		}
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++) {
			std::cin >> map[Y][X];
			max = std::max(max, map[Y][X]);
		}

	DFS(map, 0);

	std::cout << max;
}