#include <cstdio>

int main(void) {
	int A;
	scanf("%d", &A);
	for (int num = 0; num < A; num++) {
		for (int num2 = 0; num2 <= num; num2++)
			printf("*");
		printf("\n");
	}
	return 0;
}