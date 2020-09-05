#include <iostream>

int function(long long A, long long B)
{
	return A % B ? function(B, A % B) : B;
}

int main() {
	long long A, B, N;
	std::cin >> A >> B;
	N = function(A, B);
	while (N--) std::cout << '1';
}