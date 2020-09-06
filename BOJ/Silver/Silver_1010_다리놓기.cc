#include <iostream>
#include <vector>

typedef long long LL;
typedef std::vector<LL> VECTOR;

std::vector<VECTOR> DP;

LL binemialCoefficient(int N, int R) {
	if (DP[N][R] > 0) return DP[N][R];
	else if (R == 0 || N == R) return DP[N][R] = 1;
	return DP[N][R] = binemialCoefficient(N - 1, R - 1) + binemialCoefficient(N - 1, R);
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		DP = std::vector<VECTOR>(31, VECTOR(31));
		int N, R; std::cin >> N >> R;
		std::cout << binemialCoefficient(R, N) << '\n';
	}
}