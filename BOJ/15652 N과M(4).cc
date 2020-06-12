#include <iostream>

int N, M;
int number[10];

void DFS(int level) {
	if (M == level) {
		for (int i = 0; i < M; i++)
			std::cout << number[i] << ' ';
		std::cout << '\n';
		return;
	}

	for (int i = (level == 0) ? 1 : number[level - 1]; i <= N; i++) {
		number[level] = i;
		DFS(level + 1);
	}


}

int main() {
	std::cin >> N >> M;
	DFS(0);
}