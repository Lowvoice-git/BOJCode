#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

typedef std::pair<int, int> PAIR;
typedef std::priority_queue<PAIR, std::vector<PAIR>, std::greater<PAIR>> QUEUE;

std::vector<PAIR> Graph[100001];
bool visit[100001];

int Prim(int begin) {
	int result = 0, max = 0;
	QUEUE Queue;
	visit[begin] = true;

	for (int num = 0; num < Graph[begin].size(); num++)
		Queue.push(Graph[begin][num]);

	while (!Queue.empty()) {
		PAIR node = Queue.top();
		Queue.pop();

		if (visit[node.second]) continue;

		visit[node.second] = true;
		result += node.first;

		if (max < node.first)
			max = node.first;

		for (int num = 0; num < Graph[node.second].size(); num++)
			if (!visit[Graph[node.second][num].second])
				Queue.push(Graph[node.second][num]);
	}

	return result - max;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K; 
	std::cin >> N >> K;
	for (int num = 0; num < K; num++) {
		PAIR temp; int C;
		std::cin >> temp.first >> temp.second >> C;
		Graph[temp.first].push_back(std::make_pair(C, temp.second));
		Graph[temp.second].push_back(std::make_pair(C, temp.first));
	}

	std::cout << Prim(1);
}