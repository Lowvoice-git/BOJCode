#include <iostream>
#include <algorithm>

int sequence[1001], memo[1001], LLIS[1001], RLIS[1002];

int main() {
	int N, result = 0; std::cin >> N;

	for (int i = 1; i <= N; i++)
		std::cin >> sequence[i];

	for (int i = 1; i <= N; i++) {
		LLIS[i] = RLIS[N - i + 1] = 1;
		for (int j = 1; j < i; j++) {
			if (sequence[i] > sequence[j] && LLIS[j] + 1 > LLIS[i])
				LLIS[i] = LLIS[j] + 1;
			if (sequence[N - i + 1] > sequence[N - j + 1] && RLIS[N - j + 1] + 1 > RLIS[N - i + 1])
				RLIS[N - i + 1] = RLIS[N - j + 1] + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		memo[i] = LLIS[i] + RLIS[i];
		result = std::max(result, memo[i]);
	}

	std::cout << result - 1;
}