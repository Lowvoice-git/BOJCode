#include <stdio.h>
#include <algorithm>

int Array[10];

int main() {
	int result = 1;

	for (int num = 0; num < 10; num++) {
		scanf("%d", &Array[num]);
		if (Array[num] >= 42)
			Array[num] %= 42;
	}

	std::sort(Array, Array + 10);

	for (int num = 0, temp = Array[0]; num < 10; num++) {
		if (temp != Array[num]) {
			temp = Array[num];
			result++;
		}
	}
	printf("%d", result);
	return 0;
}