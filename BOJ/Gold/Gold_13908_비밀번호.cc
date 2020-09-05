#include <iostream>

int N, M, result = 0;
bool visit[10];

void DFS(int index, int level) {
	if (index == N) {
		if (level != M) return;
		result++;
		return;
	}

	for (int num = 0; num < 10; num++) {
		if (visit[num]) {
			visit[num] = false;
			DFS(index + 1, level + 1);
			visit[num] = true;
			continue;
		}
		DFS(index + 1, level);
	}
}

int main() {
	std::cin >> N >> M;
	for (int num = 0; num < M; num++) {
		int temp; std::cin >> temp;
		visit[temp] = true;
	}
	DFS(0, 0);
	std::cout << result;
}