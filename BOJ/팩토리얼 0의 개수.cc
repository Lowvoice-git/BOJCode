#include <iostream>

int main() {
	int N, result = 0;
	std::cin >> N;
	result = N / 5 + N / 25 + N / 125;
	std::cout << result;
}