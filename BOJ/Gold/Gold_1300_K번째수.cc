#include <iostream>
#include <algorithm>

int main() {
	int N, K, result = 0;
	std::cin >> N >> K;

	int begin = 1, end = K;
	while (begin <= end) {
		long long count = 0;
		int middle = (begin + end) / 2;
		for (int i = 1; i <= N; i++)
			count += std::min(middle / i, N);
		if (count < K)
			begin = middle + 1;
		else {
			result = middle;
			end = middle - 1;
		}
	}
	std::cout << result;
}