#include <iostream>
#include <vector>
#include <utility>

long long DP[101][10];

int main() {
	int N, result = 0; std::cin >> N;
	
	for (int n = 0; n <= 9; n++)
		DP[1][n] = 1;

	for (int l = 2; l <= N; l++) {
		for (int n = 0; n <= 9; n++) {
			if (n == 0) DP[l][n] = DP[l - 1][n + 1] % 1000000000;
			else if (n == 9)DP[l][n] = DP[l - 1][n - 1] % 1000000000;
			else DP[l][n] = (DP[l - 1][n - 1] + DP[l - 1][n + 1]) % 1000000000;
		}
	}

	for (int n = 1; n <= 9; n++)
		result = (result + DP[N][n]) % 1000000000;

	std::cout << result % 1000000000;
}