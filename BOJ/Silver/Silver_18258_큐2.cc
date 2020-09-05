#include <iostream>
#include <string>
#include <queue>

std::queue<int> Queue;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string query; std::cin >> query;
		if (query == "push") {
			int number; std::cin >> number;
			Queue.push(number);
			continue;
		}
		else if (query == "pop") {
			if (Queue.empty()) {
				std::cout << -1 << '\n';
				continue;
			}
			else {
				std::cout << Queue.front() << '\n';
				Queue.pop();
				continue;
			}
		}
		else if (query == "size") {
			std::cout << Queue.size() << '\n';
			continue;
		}
		else if (query == "empty") {
			std::cout << Queue.empty() << '\n';
			continue;
		}
		else if (query == "front")
			if (Queue.empty()) std::cout << -1 << '\n';
			else std::cout << Queue.front() << '\n';
		else
			if (Queue.empty()) std::cout << -1 << '\n';
			else std::cout << Queue.back() << '\n';
	}
}