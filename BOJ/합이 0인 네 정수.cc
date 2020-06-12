#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

int A[4000], B[4000], C[4000], D[4000];

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int N; std::cin >> N;
	long long result = 0;
	std::vector<int> AaddB, CaddD;

	for (int num = 0; num < N; num++)
		std::cin >> A[num] >> B[num] >> C[num] >> D[num];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AaddB.push_back(A[i] + B[j]);
			CaddD.push_back(C[i] + D[j]);
		}
	}

	std::sort(AaddB.begin(), AaddB.end());
	std::sort(CaddD.begin(), CaddD.end());
	auto end = CaddD.end();

	for (int num = 0; num < N * N; num++) {
		auto iter = std::equal_range(CaddD.begin(), end, -1 * AaddB[num]);
		int distance = std::distance(iter.first, iter.second);
		if (distance) end = iter.second;
		result += distance;
	}

	std::cout << result;
}