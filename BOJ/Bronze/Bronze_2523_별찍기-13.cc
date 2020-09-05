#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int num1 = 0; num1 < n; num1++) {
		for (int num2 = 0; num2 <= num1; num2++)
			printf("*");
		printf("\n");
	}
	for (int num1 = n - 1; num1 > 0; num1--) {
		for (int num2 = num1; num2 > 0; num2--)
			printf("*");
		printf("\n");
	}
}