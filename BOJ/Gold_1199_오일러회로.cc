#include <iostream>
#include <vector>

int N, matrix[1001][1001], edgeCount;
bool visited[1001];
std::vector<int> Vector;

void DFS(int node) {
	for (int i = 1; i <= N; i++)
		while (matrix[node][i]) {
			matrix[node][i]--;
			matrix[i][node]--;
			DFS(i);
		}
	std::cout << node << ' ';
}

int main() {
	int graphCount = 0;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			std::cin >> matrix[i][j];

			count += matrix[i][j];
			edgeCount += matrix[i][j];
		}

		if (count % 2) {
			std::cout << -1; 
			return 0;
		}
	}

	DFS(1);
}