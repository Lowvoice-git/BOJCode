#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sequence;

int main() {
	int N, K, count = 0;
	std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		sequence.push_back(temp);
	}

	while (K) {
		int index = std::upper_bound(sequence.begin(), sequence.end(), K) - sequence.begin() - 1;
		count += K / sequence[index];
		K %= sequence[index];
	}

	std::cout << count;
}