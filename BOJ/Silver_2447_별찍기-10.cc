#include <stdio.h>
char matrix[6561][6561];

void init(int N) {
	for (int Y = 0; Y < N; Y++)
		for (int X = 0; X < N; X++)
			matrix[Y][X] = ' ';
}

void solve(int N,int X,int Y) {
	if (N == 1) {
		matrix[X][Y] = '*';
		return;
	}
	int divide = N / 3;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (x == 1 && y == 1)
				continue;
			solve(divide, X + (divide * x), Y + (divide * y));
		}
	}
	return;
}

int main(void) {
	int N;
	scanf("%d", &N);
	init(N);
	solve(N, 0, 0);
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N; X++)
			printf("%c", matrix[Y][X]);
		printf("\n");
	}
	return 0;
}