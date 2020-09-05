#include <stdio.h>

int main() {
	int A, B, C, temp;
	int Array[10] = { 0, };
	scanf("%d %d %d", &A, &B, &C);
	temp = A * B * C;
	while (temp) {
		Array[temp % 10]++;
		temp /= 10;
	}
	for (int num = 0; num < 10; num++)
		printf("%d\n", Array[num]);
}