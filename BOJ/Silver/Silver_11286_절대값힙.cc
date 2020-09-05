#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>

struct compare {
	bool operator()(int A, int B) {
		if (std::abs(A) == std::abs(B))
			return A > B;
		return std::abs(A) > std::abs(B);
	}
};

typedef std::priority_queue<int, std::vector<int>, compare> QUEUE;

QUEUE Queue;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		if (temp == 0) {
			if (Queue.empty())
				std::cout << 0 << '\n';
			else {
				std::cout << Queue.top() << '\n';
				Queue.pop();
			}
		}
		else Queue.push(temp);
	}
}