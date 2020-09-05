#include <iostream>

int A, B;
long long result;

void recursive_function(long long number) {
	if (number > B) return;

	if (A <= number && number <= B) result++;

	recursive_function(number * 10 + 4);
	recursive_function(number * 10 + 7);
}

int main() {
	std::cin >> A >> B;

	recursive_function(4);
	recursive_function(7);

	std::cout << result;
}