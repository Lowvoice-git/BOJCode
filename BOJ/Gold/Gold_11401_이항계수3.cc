#include <iostream>
#include <algorithm>

#define P 1000000007LL
typedef long long LL;

LL factorial[4000001], inverse[4000001];

LL pow(LL A, LL B) {
	LL result = 1;
	while (B > 0) {
		if (B % 2) {
			result *= A;
			result %= P;
		}
		A *= A;
		A %= P;
		B /= 2;
	}

	return result;
}

int main() {
	LL N, K;
	factorial[1] = 1;
	for (int i = 2; i <= 4000000; i++)
		factorial[i] = (factorial[i - 1] * i) % P;
	inverse[4000000] = pow(factorial[4000000], P - 2);
	for (int i = 4000000 - 1; i > 0; i--)
		inverse[i] = (inverse[i + 1] * (i + 1)) % P;
	std::cin >> N >> K;
	if (N == K || !K)
		std::cout << 1;
	else {
		LL R = (factorial[N] * inverse[N - K]) % P;
		R = (R * inverse[K]) % P;
		std::cout << R;
	}
}