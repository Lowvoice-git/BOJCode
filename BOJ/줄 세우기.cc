#include <iostream>
#include <vector>
#include <queue>

int N, check[32001], result[32001];
std::vector<int> Graph[32001];

void TopologySort() {
	std::queue<int> Queue;

	for (int num = 1; num <= N; num++)
		if (check[num] == 0) Queue.push(num);

	for (int A = 1; A <= N; A++) {
		if (Queue.empty()) return;
		int temp = Queue.front();
		Queue.pop();
		result[A] = temp;
		for (int B = 0; B < Graph[temp].size(); B++) {
			int V = Graph[temp][B];
			if (--check[V] == 0) Queue.push(V);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int K; std::cin >> N >> K;
	for (int num = 0; num < K; num++) {
		int A, B; std::cin >> A >> B;
		Graph[A].push_back(B);
		check[B]++;
	}

	TopologySort();

	for (int num = 1; num <= N; num++)
		std::cout << result[num] << ' ';
}