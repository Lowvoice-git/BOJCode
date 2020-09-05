#include <iostream>
#include <vector>
#include <algorithm>

int Graph[101][101];

int main() {
	int V, E;
	std::cin >> V >> E;

	for (int num = 0; num < E; num++) {
		int A, B, cost;
		std::cin >> A >> B >> cost;
		if (Graph[A][B] != 0)
			Graph[A][B] = std::min(Graph[A][B], cost);
		else Graph[A][B] = cost;
	}

	for (int A = 1; A <= V; A++) {
		for (int B = 1; B <= V; B++) {
			if (Graph[B][A] == 0) continue;
			for (int C = 1; C <= V; C++) {
				if (Graph[A][C] == 0 || B == C) continue;
				if (Graph[B][C] == 0 || Graph[B][C] > Graph[B][A] + Graph[A][C])
					Graph[B][C] = Graph[B][A] + Graph[A][C];
			}
		}
	}

	for (int Y = 1; Y <= V; Y++) {
		for (int X = 1; X <= V; X++)
			std::cout << Graph[Y][X] << ' ';
		std::cout << '\n';
	}
}