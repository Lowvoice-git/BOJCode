#include <iostream>

int N;
long long A, B, C;

void function(int level) {
	if (level == N) return;
	C = B; B = A + B; A = C;
	function(level + 1);
}

int main() {
	std::cin >> N;
	A = 1; B = 0;
	function(1);
	std::cout << A + B;
}