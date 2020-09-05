#include <iostream>

int memo[1000001];

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < 3; i++)
		memo[i] = i;
	for (int i = 3; i <= N; i++) {
		memo[i] = memo[i - 2] + memo[i - 1];
		memo[i] %= 15746;
	}
	std::cout << memo[N];
}