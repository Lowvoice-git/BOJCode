#include <iostream>
#include <vector>

std::vector<int> Vector;

int main() {
	int N;
	scanf("%d", &N);
	for (int num = 0; num < 2; num++) Vector.push_back(1);
	for (int num = 2; num <= N; num++)
		Vector.push_back((Vector[num - 1] + Vector[num - 2] * 2) % 10007);
	printf("%d\n", Vector[N] % 10007);
}