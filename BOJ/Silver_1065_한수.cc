#include <iostream>

int main(void) {
	int number, result = 0, A, B, C;
	scanf("%d", &number);
	while (number) {
		if (number < 100)
			result++;
		else {
			A = number / 100; B = (number - (A * 100)) / 10;
			C = number - (A * 100) - (B * 10);
			if ((A - B) == (B - C))
				result++;
		}
		number--;
	}
	printf("%d", result);
	return 0;
}