#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

const int inf = 1000000000;

long long Value[16], Array[16], DP[51], label[16];
long long cash[(1 << 15) + 1][101];
int N, K;

long long GCD(long long a, long long b) {
	return b == 0 ? a : GCD(b, a % b);
}

long long DFS(int A, int B) {
	if (A == (1 << N) - 1) return B == 0;

	long long& head = cash[A][B];
	if (head != -1)return head;
	head = 0;
	for (int i = 0; i < N; ++i) {
		if (A & (1 << i)) continue;

		int mod = (DP[label[i]] * B + Array[i]) % K;
		head += DFS(A | (1 << i), mod);
	}
	return head;
}

int main() {
	Value[0] = DP[0] = 1;
	std::string bit[16];
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> bit[i];
		Value[i + 1] = Value[i] * (i + 1);
	}

	std::cin >> K;

	for (int i = 0; i < N; ++i) {
		label[i] = bit[i].size();
		for (auto j : bit[i]) Array[i] = (10 * Array[i] + j - '0') % K;
	}
	for (int i = 1; i <= 50; ++i) DP[i] = (DP[i - 1] * 10) % K;


	std::memset(cash, -1, sizeof(cash));

	long long head = DFS(0, 0);
	long long tail = GCD(head, Value[N]);

	printf("%lld/%lld", head / tail, Value[N] / tail);

	return 0;
}