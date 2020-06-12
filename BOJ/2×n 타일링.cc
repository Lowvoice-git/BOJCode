#include <iostream>

int fibonacci(int);
int memo[1001];

int main() {
	int count;
	scanf("%d", &count);
	fibonacci(count+1);
	memo[1] = 1;
	printf("%d", memo[count+1]%10007);
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
		return memo[n] = fibonacci(n - 1)%10007 + fibonacci(n - 2)%10007;
	}
}