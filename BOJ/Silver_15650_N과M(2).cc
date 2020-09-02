#include <iostream>

int N, M;
int number[10];
bool visit[10];

void DFS(int level, int K) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			std::cout << number[i] + 1 << ' ';
		std::cout << '\n';
	}

	for (int i = K; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			number[level] = i;
			DFS(level + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0, 0);
}