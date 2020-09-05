#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Array;

int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	int N, M, result = 0;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Array.push_back(std::abs(temp - M));
	}
	result = Array[0];
	for (int i = 1; i < Array.size(); i++)
		result = GCD(result, Array[i]);
	std::cout << result;
}