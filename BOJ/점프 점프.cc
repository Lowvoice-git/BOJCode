#include <iostream>
#include <vector>
#include <utility>

int memo[1001] = { 0, };

int main() {
	memo[1] = 1;
	int N; std::cin >> N;
	for (int num = 1; num <= N; num++) {
		int temp; std::cin >> temp;
		if (!memo[num])break;
		for (int i = 1; i <= temp; i++) {
			if (i + num > 1000)break;
			if (memo[i + num] > memo[num] + 1 || !memo[i + num])
				memo[i + num] = memo[num] + 1;
		}
	}

	if (memo[N]) std::cout << memo[N] - 1;
	else std::cout << -1;
}