#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int main() {
	std::string A;
	std::cin >> A;
	std::sort(A.begin(), A.end(), std::greater<char>());
	std::cout << A;
}