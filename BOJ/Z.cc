#include <stdio.h>
#include <math.h>

int TargetY, TargetX, result;

int Check_Target(int LeftX, int RightX,int LeftY, int RightY) {
	if ((TargetX >= LeftX&&TargetX <= RightX) && (TargetY >= LeftY&&TargetY <= RightY))
		return true;
	return false;
}

bool Divide_And_ConQuer(int size, int pointX, int pointY) {
	if (Check_Target(pointX, pointX + (size - 1), pointY, pointY + (size - 1))) {
		if (pointY == TargetY&&pointX == TargetX) {
			printf("%d", result);
			return true;
		}
		Divide_And_ConQuer(size / 2, pointX, pointY); result++;
		Divide_And_ConQuer(size / 2, pointX + (size / 2), pointY); result++;
		Divide_And_ConQuer(size / 2, pointX, pointY + (size / 2)); result++;
		Divide_And_ConQuer(size / 2, pointX + (size / 2), pointY + (size / 2));
	}
	else {
		result += (size * size) - 1;
		return true;
	}
	return false;
}

int main(void) {
	int N, result = 0;
	scanf("%d %d %d", &N, &TargetY, &TargetX);
	N = (int)pow(2, N);
	Divide_And_ConQuer(N, 0, 0);
	return 0;
}