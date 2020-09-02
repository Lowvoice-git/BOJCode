#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

int number;
int32_t Array[1000001];

void Function() {
	Array[1] = 0;
	for (int num = 2; num <= number; num++) {
		Array[num] = Array[num - 1] + 1;
		if (num % 2 == 0)
			Array[num] = std::min(Array[num], Array[num / 2] + 1);
		if (num % 3 == 0)
			Array[num] = std::min(Array[num], Array[num / 3] + 1);
	}
}

int main(void) {
	memset(Array, 0, sizeof(int32_t) * (number + 1));
	scanf("%d", &number);
	Function();
	printf("%d", Array[number]);
	return 0;
}