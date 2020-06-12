#include <iostream>

long long memo[1500050];

void fibonacci() {
	memo[0] = 0; memo[1] = 1;
	for (int num = 0; num < 1500000; num++)
		memo[num + 2] = (memo[num + 1] + memo[num]) % 1000000;
}

int main() {
	long long n;
	std::cin >> n;
	fibonacci();
	std::cout << memo[n % 1500000] << '\n';
	return 0;
}