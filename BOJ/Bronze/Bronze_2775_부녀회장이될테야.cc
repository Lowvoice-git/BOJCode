#include <iostream>

int function(int A, int B) {
	int sum = 0;
	if (A == 0) return 0;

	if (A == 1) {
		for (int i = 1; i <= B; i++) sum += i;
		return sum;
	}

	for (int i = 1; i <= B; i++)
		sum += function(A - 1, i);
	
	return sum;
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		int A, B;
		std::cin >> A >> B;
		std::cout << function(A, B) << '\n';
	}
}