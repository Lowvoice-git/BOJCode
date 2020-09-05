#include <iostream>
#include <vector>
#include <utility>

int Graph[401][401];
std::vector<std::pair<int, int>> list;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int V, E, R;
	std::cin >> V >> E;

	for (int num = 0; num < E; num++) {
		int A, B;
		std::cin >> A >> B;
		Graph[A][B] = -1;
		Graph[B][A] = 1;
	}

	std::cin >> R;
	for (int num = 0; num < R; num++) {
		int A, B;
		std::cin >> A >> B;
		list.push_back(std::make_pair(A, B));
	}

	for (int A = 1; A <= V; A++)
		for (int B = 1; B <= V; B++)
			for (int C = 1; C <= V; C++)
				if (!Graph[B][C])
					if (Graph[B][A] == 1 && Graph[A][C] == 1)
						Graph[B][C] = 1;
					else if (Graph[B][A] == -1 && Graph[A][C] == -1)
						Graph[B][C] = -1;

	for (int num = 0; num < R; num++)
		std::cout << Graph[list[num].first][list[num].second] << '\n';
}