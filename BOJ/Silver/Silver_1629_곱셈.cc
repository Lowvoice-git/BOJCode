#include <iostream>

typedef long long LL;

LL A, B, C;
int result;

LL pow(LL number, LL indices) {
	if (indices == 0)
		return 1;
	else if (indices == 1)
		return number;

	if (indices % 2 > 0)
		return (pow(number,indices - 1) * number) % C;

	LL half = pow(number, indices / 2);
	half %= C;

	return (half * half) % C;
}

int main() {
	std::cin >> A >> B >> C;
	std::cout << pow(A, B) % C;
}