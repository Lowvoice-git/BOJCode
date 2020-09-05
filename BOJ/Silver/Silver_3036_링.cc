#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> number, result;

int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		number.push_back(temp);
	}
	int gcd;
	for (int i = 1; i < N; i++) {
		gcd = GCD(number[i], number[0]);
		std::cout << number[0] / gcd << '/' << number[i] / gcd << '\n';
	}
}