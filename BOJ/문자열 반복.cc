#include <stdio.h>
#include <string.h>

int main(void) {
	int N, M, index = 0;
	char string[21];
	char result[161];
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		scanf("%d %s", &M, string);
		for (int num = 0; num < strlen(string); num++)
			for (int num2 = 0; num2 < M; num2++, index++)
				result[index] = string[num];
		for (int num3 = 0; num3 < strlen(string)*M; num3++)
			printf("%c", result[num3]);
		printf("\n");
		index = 0;
	}
}