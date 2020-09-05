#include <iostream>
#include <algorithm>
#include <cstring>

int N, K, E;
int check[1001];
int delay[1001];
int matrix[1001][1001];

int DFS(int V) {
	int &result = check[V], second = 0;
	if (result != -1) return result;
	for (int num = 1; num <= N; num++)
		if (matrix[num][V])
			second = std::max(second, DFS(num));
	return result = second + delay[V];
}

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
	int T; std::cin >> T;
	while (T--) {
		std::memset(check, -1, sizeof(check));
		std::memset(matrix, 0, sizeof(matrix));

		std::cin >> N >> K;
		for (int num = 1; num <= N; num++)
			std::cin >> delay[num];
		for (int num = 0; num < K; num++) {
			int Y, X; std::cin >> Y >> X;
			matrix[Y][X] = 1;
		}
		std::cin >> E;
		std::cout << DFS(E) << '\n';
	}
}