#include <iostream>
#include <queue>

int N, M, K;
bool matrix[1001][1001];
bool vortex[1001];

void DFS(int K) {
	std::cout << K << ' ';
	vortex[K] = true;
	for (int num = 1; num <= N; num++) {
		if (!matrix[K][num] || vortex[num]) continue;
		DFS(num);
	}
}

void BFS(int K) {
	std::queue<int> Queue;
	Queue.push(K);
	vortex[K] = false;
	while (!Queue.empty()) {
		K = Queue.front();
		std::cout << Queue.front() << ' ';
		Queue.pop();
		for (int num = 1; num <= N; num++) {
			if (!vortex[num] || !matrix[K][num]) continue;
			Queue.push(num); vortex[num] = false;
		}
	}
}

int main() {
	std::cin >> N >> M >> K;
	for (int num = 0; num < M; num++) {
		int begin, end; std::cin >> begin >> end;
		matrix[begin][end] = matrix[end][begin] = true;
	}
	DFS(K);
	std::cout << '\n';
	BFS(K);
}