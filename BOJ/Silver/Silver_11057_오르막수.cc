#include <iostream>

#define MOD 10007;
typedef long long LL;

int DP[10];

int main() {
	int N; std::cin >> N;

	for (int i = 0; i < 10; i++)
		DP[i] = 1;

	for (int i = 1; i < N; i++)
		for (int j = 1; j < 10; j++)
			DP[j] = (DP[j] + DP[j - 1]) % MOD;

	LL sum = 0;
	for (int i = 0; i < 10; i++)
		sum += DP[i];

	std::cout << sum % MOD;
}