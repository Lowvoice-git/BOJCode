#include <iostream>
#include <vector>

int count;
bool check;
int matrix[100001];
bool visited[100001], done[100001];

void DFS(int index) {
	visited[index] = true;

	int nextNode = matrix[index];

	if (!visited[nextNode]) DFS(nextNode);
	else if (!done[nextNode]) {
		for (int i = nextNode; i != index; i = matrix[i])
			count++;
		count++;
	}

	done[index] = true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int N; std::cin >> N;
		for (int i = 1; i <= N; i++) {
			std::cin >> matrix[i];
			visited[i] = false;
			done[i] = false;
		}

		count = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				DFS(i);
		}

		std::cout << N - count << '\n';
	}
}