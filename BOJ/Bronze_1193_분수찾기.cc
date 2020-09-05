#include <stdio.h>

int main(void) {
	int N, count = 1, left;
	scanf("%d", &N);
	while (true) {
		if (N - count <= 0) break;
		N -= count;
		count++;
	}
	if (count % 2 == 1) {
		for (left = 1; left <= N; left++, count--);
		printf("%d/%d", count + 1, N);
	}
	else {
		for (left = 1; left <= N; left++, count--);
		printf("%d/%d", N, count + 1);
	}
}