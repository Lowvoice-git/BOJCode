#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

typedef std::pair<int, int> PAIR;

std::vector<PAIR> Graph[101];

std::vector<int> Dijkstra(int begin, int N) {
	std::vector<int> result(N, INT_MAX);
	std::priority_queue<PAIR, std::vector<PAIR>, std::greater<PAIR>> Queue;

	result[begin] = 0;
	Queue.push(std::make_pair(begin, 0));

	while (!Queue.empty()) {
		PAIR vortex = Queue.top();
		Queue.pop();

		if (result[vortex.first] < vortex.second)
			continue;

		for (int num = 0; num < Graph[vortex.first].size(); num++) {
			PAIR next = Graph[vortex.first][num];

			if (result[next.first] > next.second + vortex.second) {
				result[next.first] = next.second + vortex.second;
				Queue.push(std::make_pair(next.first, result[next.first]));
			}
		}
	}
	return result;
}

int main() {
	int N, M, E, result = 0;
	std::cin >> N >> M >> E;
	std::vector<int> V(N + 1);
	for (int num = 1; num <= N; num++) {
		int temp; std::cin >> temp;
		V[num] = temp;
	}
	for (int num = 0; num < E; num++) {
		int cost; PAIR temp;
		std::cin >> temp.first >> temp.second >> cost;
		Graph[temp.first].push_back(std::make_pair(temp.second, cost));
		Graph[temp.second].push_back(std::make_pair(temp.first, cost));
	}

	std::vector<std::vector<int>> list(N + 1);
	for (int num = 1; num <= N; num++) {
		int sum = 0; list[num] = Dijkstra(num, N + 1);
		for (int index = 1; index < list[num].size(); index++)
			if (M >= list[num][index]) sum += V[index];
		result = std::max(result, sum);
	}
	std::cout << result;
}