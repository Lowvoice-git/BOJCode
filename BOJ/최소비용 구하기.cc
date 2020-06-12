#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <climits>

typedef std::pair<int, int> PAIR;

std::vector<PAIR> Graph[20001];

std::vector<int> BFS(int begin, int count) {
	std::vector<int> Vortex(count, INT_MAX);
	Vortex[begin] = 0;
	std::priority_queue<PAIR,std::vector<PAIR>,std::greater<PAIR>> Queue;
	Queue.push({ begin,0 });

	while (!Queue.empty()) {
		int vortex_number = Queue.top().first;
		int vortex_cost = Queue.top().second;
		Queue.pop();

		if (Vortex[vortex_number] < vortex_cost) continue;

		for (int num = 0; num < Graph[vortex_number].size(); num++) {
			int vortex_temp = Graph[vortex_number][num].first;
			int cost = vortex_cost + Graph[vortex_number][num].second;

			if (Vortex[vortex_temp] > cost) {
				Vortex[vortex_temp] = cost;
				Queue.push({ vortex_temp,Vortex[vortex_temp] });
			}
		}
	}

	return Vortex;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int V, E, begin, end; std::cin >> V >> E;

	for (int num = 0; num < E; num++) {
		PAIR temp; int w;
		std::cin >> temp.first >> temp.second >> w;
		Graph[temp.first].push_back({ temp.second,w });
	}

	std::cin >> begin >> end;

	auto Vortex = BFS(begin, V + 1);

	std::cout << Vortex[end];
}