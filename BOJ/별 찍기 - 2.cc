#include <cstdio>

int main(void) {
	int A;
	scanf("%d", &A);
	for (int num = 0; num < A; num++) {
		for (int num2 = 1; num2 < A-num; num2++)
			printf(" ");
		for (int num3 = 0; num3 <= num; num3++)
			printf("*");
		printf("\n");
	}
	return 0;
}