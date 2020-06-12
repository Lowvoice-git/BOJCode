#include <iostream>
#include <vector>
#include <cstring>

int V, E;
std::vector<int> Graph[20001];
int visit[20001];

void DFS(int V, int color) {
	visit[V] = color;
	for (int num = 0; num < Graph[V].size(); num++) {
		int node = Graph[V][num];
		if (!visit[node]) DFS(node, 3 - color);
	}
}

bool Check() {
	for (size_t i = 1; i <= V; i++) {
		for (size_t j = 0; j < Graph[i].size(); j++) {
			int node = Graph[i][j];
			if (visit[i] == visit[node]) return false;
		}
	}
	return true;
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		for (int num = 1; num < 20001; num++) Graph[num].clear();
		std::memset(visit, 0, sizeof(int) * 20001);
		std::cin >> V >> E;
 		for (int num = 0; num < E; num++) {
			int left, right;
			std::cin >> left >> right;
			Graph[left].push_back(right);
			Graph[right].push_back(left);
		}

		for (int num = 1; num <= V; num++) {
			if (visit[num] == 0) DFS(num, 1);
		}

		if (Check()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}