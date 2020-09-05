#include <iostream>
#include <algorithm>

int memo[301], Array[301];

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> Array[i];

	memo[0] = Array[0];
	memo[1] = std::max(Array[0] + Array[1], Array[1]);
	memo[2] = std::max(Array[0] + Array[2], Array[1] + Array[2]);

	for (int i = 3; i < N; i++)
		memo[i] = std::max(memo[i - 2] + Array[i], memo[i - 3] + Array[i - 1] + Array[i]);
	
	std::cout << memo[N - 1];
}