#include <iostream>
#include <vector>
#include <climits>

std::vector<long long> vector;

int main() {
	int N, cost;
	long long left = 0, right = LLONG_MAX, result = 0;
	std::cin >> N >> cost;
	for (int num = 0; num < N; num++) {
		long long temp; std::cin >> temp;
		vector.push_back(temp);
	}
	while (left <= right) {
		long long middle = (left + right) / 2;
		int max = 0;

		for (int num = 0; num < N; num++)
			max += vector[num] / middle;

		if (max >= cost) {
			left = middle + 1;
			if (middle > result)result = middle;
		}
		else right = middle - 1;
	}
	std::cout << result;
}