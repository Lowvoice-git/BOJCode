#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long LL;
typedef std::pair<LL, std::pair<LL, LL>> PAIR;

std::vector<PAIR> Vector;

LL GCD(LL A, LL B) {
	return A % B ? GCD(B, A % B) : B;
}

LL LCM(LL A, LL B) {
	return A * B / GCD(A, B);
}

int main() {
	int A, B; std::cin >> A >> B;

	LL gcd = A, lcm = B, count = 2;
	while (A <= B) {
		if (gcd == GCD(A, B) && lcm == LCM(A, B))
			Vector.push_back({ A + B, { A,B } });

		A = gcd * count;
		B = lcm / count;
		count++;
	}

	std::sort(Vector.begin(), Vector.end());

	std::cout << Vector.front().second.first << ' ' << Vector.front().second.second;
}