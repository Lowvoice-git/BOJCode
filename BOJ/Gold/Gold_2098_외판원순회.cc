#include <iostream>

int N;
int matrix[17][17];
int DP[16][1 << 16];

int TSP(int V, int visit) {
	int cost;
	int result = DP[V][visit];

	if (result) return result;

	if (visit == (1 << N) - 1) {
		if (matrix[V][0] != 0)
			return matrix[V][0];
		return 1000000000;
	}

	result = 1000000000;

	for (int num = 0; num < N; num++) {
		if ((visit & 1 << num) || (matrix[V][num] == 0)) continue;
		cost = TSP(num, (visit | 1 << num)) + matrix[V][num];
		if (cost < result) result = cost;
	}

	DP[V][visit] = result;

	return result;
}

int main() {
	std::cin >> N;
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			std::cin >> matrix[Y][X];
	std::cout << TSP(0, 1);
}