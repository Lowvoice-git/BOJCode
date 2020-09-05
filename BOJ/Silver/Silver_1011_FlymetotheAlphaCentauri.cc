#include <stdio.h>

int function(int distance) {
	long long min, max, powN, num = 0;
	while (++num) {
		powN = num * num;
		min = powN - num + 1;
		max = powN + num;
		if (min <= distance&&powN >= distance) {
			return (num * 2) - 1;
		}
		else if (powN < distance&&max >= distance)
			return num * 2;
	}
}

int main(void) {
	int N, start, end;
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		scanf("%d %d", &start, &end);
		printf("%d\n", function(end - start));
	}
}