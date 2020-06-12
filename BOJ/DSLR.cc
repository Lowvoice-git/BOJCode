#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

int start, end;

std::string BFS() {
	std::queue<std::pair<int, std::string>> Queue;
	bool visit[10000] = { false, }; visit[start] = true;
	Queue.push(std::make_pair(start, ""));

	while (!Queue.empty()) {
		int temp;
		std::pair<int, std::string> node = Queue.front();
		Queue.pop();

		if (node.first == end) return node.second;

		temp = (node.first * 2) % 10000;
		if (!visit[temp]) {
			visit[temp] = true;
			Queue.push(std::make_pair(temp, node.second + 'D'));
		}

			temp = node.first == 0 ? 9999 : node.first - 1;
		if (!visit[temp]) {
			visit[temp] = true;
			Queue.push(std::make_pair(temp, node.second + 'S'));
		}

			temp = (node.first % 1000) * 10 + node.first / 1000;
		if (!visit[temp]) {
			visit[temp] = true;
			Queue.push(std::make_pair(temp, node.second + 'L'));
		}

			temp = (node.first % 10) * 1000 + (node.first / 10);
		if (!visit[temp]) {
			visit[temp] = true;
			Queue.push(std::make_pair(temp, node.second + 'R'));
		}
	}
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		std::cin >> start >> end;
		std::cout << BFS() << '\n';
	}
}