#include <cstdio>

int main(void) {
	int A;
	scanf("%d", &A);
	for (int num = 1; num < 10; num++)
		printf("%d * %d = %d\n", A, num, A * num);
	return 0;
}