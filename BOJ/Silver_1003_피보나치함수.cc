#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);
int memo[41];

int main() {
	int count;
	int *data;
	scanf("%d", &count);
	data = (int*)calloc(count, sizeof(int));
	for (int num = 0; num < count; num++)
		scanf("%d", &data[num]);
	fibonacci(41);
	memo[1] = 1;
	for (int num = 0; num < count; num++) {
		if (data[num] != 0)
			printf("%d %d\n", memo[data[num] - 1], memo[data[num]]);
		else
			printf("1 0\n");
	}

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