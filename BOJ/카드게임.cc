#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int memo[2000][2000];
int N;
int left[2000], right[2000];

int DP(int A, int B) {
	if (A >= N || B >= N) return 0;
	if (memo[A][B] != -1) return memo[A][B];
	memo[A][B] = std::max(DP(A + 1, B), DP(A + 1, B + 1));
	if (left[A] > right[B])
		memo[A][B] = std::max(right[B] + DP(A, B + 1), memo[A][B]);
	return memo[A][B];
}

int main() {
	std::cin >> N;
	std::memset(memo, -1, sizeof(memo));
	for (int num = 0; num < N; num++)
		std::cin >> left[num];
	for (int num = 0; num < N; num++)
		std::cin >> right[num];
	std::cout << DP(0, 0);
}