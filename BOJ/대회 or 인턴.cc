#include <iostream>
#include <algorithm>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	std::cout << std::min(std::min(N / 2, M), (N + M - K) / 3) << "\n";
}