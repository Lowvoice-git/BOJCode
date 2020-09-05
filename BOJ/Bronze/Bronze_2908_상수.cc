#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string A, B;
	std::cin >> A >> B;
	std::reverse(A.begin(), A.end());
	std::reverse(B.begin(), B.end());

	if (A > B) std::cout << A;
	else std::cout << B;
}