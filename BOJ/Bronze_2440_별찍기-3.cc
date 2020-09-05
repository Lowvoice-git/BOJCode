#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int num1 = 0; num1 < n; num1++) {
		for (int num2 = 0; num2 < n - num1; num2++)
			printf("*");
		printf("\n");
	}
}