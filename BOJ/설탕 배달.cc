#include <stdio.h>

int main(void) {
	int value = 0;
	int A_count = 0;
	int B_count = 0;

	scanf("%d", &value);

	A_count = value / 5;
	value %= 5;

	while(A_count>=0) {
		if (value % 3 == 0) {
			B_count = value / 3;
			value %= 3;
			break;
		}
		A_count -= 1;
		value += 5;
	}

	if (value != 0) printf("-1");
	else printf("%d", A_count + B_count);
}