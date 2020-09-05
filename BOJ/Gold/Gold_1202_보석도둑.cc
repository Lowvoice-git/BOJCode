#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

std::vector<std::pair<int, int>> V;
std::vector<int> W;

int main() {
	int N, K; std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int A, B; std::cin >> A >> B;
		V.push_back({ A,B });
	}
	for (int i = 0; i < K; i++) {
		int temp; std::cin >> temp;
		W.push_back(temp);
	}

	std::sort(V.begin(), V.end());
	std::sort(W.begin(), W.end());
	
	long long result = 0;
	std::priority_queue<int> Queue;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && V[j].first <= W[i])
			Queue.push(V[j++].second);

		if (!Queue.empty()) {
			result += Queue.top();
			Queue.pop();
		}
	}

	std::cout << result;
}