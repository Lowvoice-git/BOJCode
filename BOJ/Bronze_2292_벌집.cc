#include <stdio.h>

int main(void) {
	int N, left = 1, right = 1, result = 1;
	scanf("%d", &N);
	while (true) {
		if (left <= N && right >= N) {
			printf("%d", result);
			return 0;
		}
		left = right + 1;
		right += 6 * result;
		result++;
	}
}