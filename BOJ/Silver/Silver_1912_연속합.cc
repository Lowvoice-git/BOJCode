#include <iostream>
#include <vector>
#include <algorithm>

int memo[100001];
std::vector<int> sequence;

int main() {
	int N, result = -1000; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		sequence.push_back(temp);
	}

	memo[0] = sequence[0];

	for (int i = 1; i < N; i++)
		memo[i] = std::max(0, memo[i - 1]) + sequence[i];

	for (int i = 0; i < N; i++)
		result = std::max(result, memo[i]);

	std::cout << result;
}