#include <stdio.h>

char matrix[64][65];

void Quad_Tree(int size, int startX, int startY) {
	bool check = true;
	char First_Element = matrix[startY][startX];
	for (int Y = startY; Y < (size + startY); Y++) {
		for (int X = startX; X < (size + startX); X++) {
			if (First_Element != matrix[Y][X])
				check = false;
		}
	}
	if (check)
		printf("%c", First_Element);
	else {
		printf("(");
		Quad_Tree(size / 2, startX, startY);
		Quad_Tree(size / 2, startX + size / 2, startY);
		Quad_Tree(size / 2, startX, startY + size / 2);
		Quad_Tree(size / 2, startX + size / 2, startY + size / 2);
		printf(")");
	}
}

int main(void) {
	int N;
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		scanf("%s", matrix[num]);
	}
	Quad_Tree(N, 0, 0);
	return 0;
}