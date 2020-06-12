#include <stdio.h>

int fibonacci(int);
int memo[46];

int main() {
	int count;
	scanf("%d", &count);
	fibonacci(46);
	memo[1] = 1;
	printf("%d", memo[count]);
	return 0;
}

int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	else if (memo[n] != 0) {
		return memo[n];
	}
	else {
		return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}