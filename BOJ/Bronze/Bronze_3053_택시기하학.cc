#include <iostream>

#define PI 3.14159265358979323846

int main() {
	double R; std::cin >> R;
	double result1 = R * R * PI;
	double result2 = R * R * 2;

	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << result1 << '\n' << result2;
}