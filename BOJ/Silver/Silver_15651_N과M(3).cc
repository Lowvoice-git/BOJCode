#include <iostream>

int N, M;
int number[10];

void DFS(int level) {
	if (M == level) {
		for (int num = 0; num < M; num++)
			std::cout << number[num] << ' ';
		std::cout << '\n';
		return;
	}

	for (int num = 1; num <= N; num++) {
		number[level] = num;
		DFS(level + 1);
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0);
}