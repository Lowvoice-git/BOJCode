#include <iostream>

int function(int A, int B, int C) {
	if (C - B <= 0) return -1;
	else return A / (C - B) + 1;
}

int main() {
	int A, B, C;
	std::cin >> A >> B >> C;
	std::cout << function(A, B, C);
	return 0;
}