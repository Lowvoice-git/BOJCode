#include <stdio.h>

int m = 1;

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
	function(n);
	m -= 4;
	for (int num1 = 1; num1 < n; num1++) {
		for (int num2 = 0; num2 < num1; num2++)
			printf(" ");
		for (int num2 = 0; num2 < m; num2++)
			printf("*");
		printf("\n"); m -= 2;
	}
}