#include <iostream>

int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	int T, N, Array[101];
	std::cin >> T;
	while (T--) {
		long long sum = 0;
		std::cin >> N;
		for (int i = 0; i < N; i++)
			std::cin >> Array[i];
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				sum += GCD(Array[i], Array[j]);
		std::cout << sum << '\n';
	}
}