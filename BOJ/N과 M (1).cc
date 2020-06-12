#include <iostream>

int N, M;
int number[10];
bool visit[10];

void DFS(int level) {
	if (M == level) {
		for (int num = 0; num < M; num++)
			std::cout << number[num] << ' ';
		std::cout << '\n';
		return;
	}

	for (int num = 1; num <= N; num++) {
		if (visit[num])continue;
		visit[num] = true;
		number[level] = num;
		DFS(level + 1);
		visit[num] = false;
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0);
}