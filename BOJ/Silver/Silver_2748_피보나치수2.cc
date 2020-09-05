#include <iostream>

long long memo[100];

long long fibonachi(int index) {
	if (!memo[index]) return memo[index] = fibonachi(index - 1) + fibonachi(index - 2);
	else return memo[index];
}

int main() {
	memo[2] = memo[3] = 1;
	int index;
	std::cin >> index;
	std::cout << fibonachi(index + 1);
}