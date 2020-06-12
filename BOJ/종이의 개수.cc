#include <stdio.h>
#include <math.h>

int matrix[2187][2187];
int temp, sum;
int result[3];
bool check;

bool Divide_And_Conquer(int size, int pointX, int pointY) {
	temp = matrix[pointY][pointX]; sum = 0;
	for (int Y = pointY; Y < size + pointY; Y++) {
		for (int X = pointX; X < size + pointX; X++) {
			if (temp == matrix[Y][X]) {
				temp = matrix[Y][X]; sum++; check = true;
			}
			else {
				check = false; break;
			}
		}
		if (!check) break;
	}
	if (check) {
		sum /= (int)pow(size, 2);
		result[temp + 1] += sum;
		return true;
	}
	else {
		size /= 3;
		Divide_And_Conquer(size, pointX, pointY);
		Divide_And_Conquer(size, pointX + size, pointY);
		Divide_And_Conquer(size, pointX + size + size, pointY);
		Divide_And_Conquer(size, pointX, pointY + size);
		Divide_And_Conquer(size, pointX + size, pointY + size);
		Divide_And_Conquer(size, pointX + size + size, pointY + size);
		Divide_And_Conquer(size, pointX, pointY + size + size);
		Divide_And_Conquer(size, pointX + size, pointY + size + size);
		Divide_And_Conquer(size, pointX + size + size, pointY + size + size);
	}
	return false;
}

int main(void) {
	int N; check = false;
	for (int num = 0; num < 3; num++)
		result[num] = 0;
	scanf("%d", &N);
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N; X++)
			scanf("%d", &matrix[Y][X]);
	}
	Divide_And_Conquer(N, 0, 0);
	for (int num = 0; num < 3; num++)
		printf("%d\n", result[num]);
	return 0;
}