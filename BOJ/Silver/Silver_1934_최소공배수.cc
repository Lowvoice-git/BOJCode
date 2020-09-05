#include <iostream>

int GCD(int A, int B) {
	while (B) {
		int mod = A % B;
		A = B; B = mod;
	}
	return A;
}

int LCM(int A, int B) {
	return A * B / GCD(A, B);
}

int main() {
	int N, A, B;
	std::cin >> N;
	while (N--) {
		std::cin >> A >> B;
		std::cout << LCM(A, B) << '\n';
	}
}