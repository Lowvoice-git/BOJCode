#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <functional>

typedef std::pair<int,int> PAIR;

std::vector<PAIR> Graph[501];
std::vector<PAIR> track[501];
bool visit[501][501];

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

			if (next.second == -1) continue;
			
			if (result[next.first] > next.second + vortex.second) {
				result[next.first] = next.second + vortex.second;
				Queue.push(std::make_pair(next.first, result[next.first]));

				track[next.first].clear();
				track[next.first].push_back(std::make_pair(vortex.first, next.second + vortex.second));
			}
			else if (result[next.first] == next.second + vortex.second)
				track[next.first].push_back(std::make_pair(vortex.first, next.second + vortex.second));
		}
	}

	return result;
}

void BFS(int end) {
	std::queue<int> Queue;
	Queue.push(end);

	while (!Queue.empty()) {
		int vortex = Queue.front();
		Queue.pop();

		for (int num = 0; num < track[vortex].size(); num++) {
			int next = track[vortex][num].first;

			if (visit[vortex][next]) continue;

			for (int i = 0; i < Graph[next].size(); i++)
				if (Graph[next][i].first == vortex)
					Graph[next][i].second = -1;

			Queue.push(next);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int N, M, begin, end;

	while (true) {
		std::memset(visit, false, sizeof(visit));
		for (int num = 0; num < 501; num++) {
			track[num].clear(); Graph[num].clear();
		}

		std::cin >> N >> M;
		if (!N && !M) break;
		std::cin >> begin >> end;

		for (int num = 0; num < M; num++) {
			PAIR temp; int cost;
			std::cin >> temp.first >> temp.second >> cost;
			Graph[temp.first].push_back(std::make_pair(temp.second,cost));
		}

		Dijkstra(begin, N);
		BFS(end);
		auto result = Dijkstra(begin, N);

		if (result[end] == INT_MAX) std::cout << "-1" << '\n';
		else std::cout << result[end] << '\n';
	}
}