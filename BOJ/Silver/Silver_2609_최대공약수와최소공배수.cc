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
	int A, B;
	std::cin >> A >> B;
	std::cout << GCD(A, B) << '\n' << LCM(A, B);
}