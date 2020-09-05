#include <stdio.h>

int m;

void function(int n) {
	if (n <= 0) return;
	for (int num = 0; num < n - 1; num++)
		printf(" ");
	for (int num = 0; num < m; num++)
		printf("*");
	printf("\n"); m += 2;
	function(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	m = 2 * n - 1;
	for (int num1 = 0; num1 < n-1; num1++) {
		for (int num2 = 0; num2 < num1; num2++)
			printf(" ");
		for (int num2 = 0; num2 < m; num2++)
			printf("*");
		printf("\n"); m -= 2;
	}
	function(n);
}