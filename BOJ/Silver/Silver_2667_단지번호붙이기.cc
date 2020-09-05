#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int matrix[25][25], count[323];
std::vector<std::pair<int, int>> direction = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int result, N;

bool Check(int y, int x) {
	return (y >= 0 && y < N) && (x >= 0 && x < N);
}

void DFS(int y, int x, int k) {
	matrix[y][x] = k;

	for (int num = 0; num < 4; num++) {
		int ny = y + direction[num].first;
		int nx = x + direction[num].second;

		if (Check(ny, nx) && matrix[ny][nx] == 1) DFS(ny, nx, k);
	}
}

int main() {
	std::cin >> N;
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N; X++) {
			char temp; std::cin >> temp;
			matrix[Y][X] = temp - '0';
		}
	}

	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N; X++) {
			if (matrix[Y][X] == 1) {
				result++; DFS(Y, X, result + 1);
			}
		}
	}
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N; X++) {
			if (matrix[Y][X] > 1) {
				count[matrix[Y][X] - 2]++;
			}
		}
	}
	std::sort(count, count + result);
	std::cout << result << '\n';
	for (int num = 0; num < result; num++)
		std::cout << count[num] << '\n';
}