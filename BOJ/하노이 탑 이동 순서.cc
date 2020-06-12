#include <stdio.h>
#include <vector>

std::vector<std::pair<int, int>> result;

void Hanoi_Tower(int N, int A, int B, int C) {
	if (N == 1)
		result.push_back({ A,C });
	else {
		Hanoi_Tower(N - 1, A, C, B);
		result.push_back({ A,C });
		Hanoi_Tower(N - 1, B, A, C);
	}
}

int main(void) {
	int N;
	scanf("%d", &N);
	Hanoi_Tower(N, 1, 2, 3);
	printf("%d\n", result.size());
	for (int num = 0; num < result.size(); num++)
		printf("%d %d\n", result[num].first, result[num].second);
	return 0;
}