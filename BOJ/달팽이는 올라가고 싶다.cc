#include <iostream>

int main() {
	int A, B, V, result = 0;
	std::cin >> A >> B >> V;
	result = (V - B - 1) / (A - B) + 1;
	std::cout << result;
}