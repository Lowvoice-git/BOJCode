#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> PAIR;

int main() {
	int N; std::cin >> N;
	std::vector<PAIR> V(N);
	std::vector<int> result(N, 1);
	for (int i = 0; i < N; i++)
		std::cin >> V[i].first >> V[i].second;
	
	for (int i = 0; i < V.size(); i++)
		for (int j = 0; j < V.size(); j++) {
			if (i == j) continue;
			else if (V[i].first < V[j].first && V[i].second < V[j].second)
				result[i]++;
		}

	for (int i = 0; i < N; i++)
		std::cout << result[i] << ' ';
}