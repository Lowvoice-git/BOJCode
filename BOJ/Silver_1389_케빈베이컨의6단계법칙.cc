#include <iostream>
#include <climits>
#include <algorithm>

int N, M;
int graph[101][101];

void floyd() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (i == j) continue;
				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0)
						graph[i][j] = graph[i][k] + graph[k][j];
					else
						graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
				}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++)	{
		int node1, node2;
		std::cin >> node1 >> node2;

		graph[node1][node2] = graph[node2][node1] = 1;
	}

	floyd();

	int temp = INT_MAX;
	int result = 0;

	for (int Y = 1; Y <= N; Y++){
		int sum = 0;
		for (int X = 1; X <= N; X++)
			sum += graph[Y][X];
		if (temp > sum){
			temp = sum;
			result = Y;
		}
	}

	std::cout << result;
	return 0;
}