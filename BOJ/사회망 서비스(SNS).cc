#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int N;
std::vector<int> V[1000001];
int DP[1000001][2];
bool visit[1000001];

void DFS(int index) {
	visit[index] = true;
	DP[index][0] = 0; DP[index][1] = 1;

	for (int num = 0; num < V[index].size(); num++)
		if (!visit[V[index][num]])
			DFS(V[index][num]);

	for (int num = 0; num < V[index].size(); num++) {
		if (!visit[V[index][num]]) {
			DP[index][0] += DP[V[index][num]][1];
			DP[index][1] += std::min(DP[V[index][num]][0], DP[V[index][num]][1]);
		}
	}

	visit[index] = false;
	return;
}

int main() {
	std::cin >> N;
	for (int num = 1; num < N; num++) {
		std::pair<int, int> temp; std::cin >> temp.first >> temp.second;
		V[temp.first].push_back(temp.second);
		V[temp.second].push_back(temp.first);
	}
	DFS(1);
	std::cout << std::min(DP[1][0], DP[1][1]);
}