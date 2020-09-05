#include <cstdio>
#include <algorithm>

int main(void) {
	int N;
	float grade[1000], sum = 0, max;
	scanf("%d", &N);
	for (int num = 0; num < N; num++)
		scanf("%d", &grade[num]);
	std::sort(grade, grade + N);
	max = grade[N-1];
	for (int num = 0; num < N; num++) {
		grade[num] = (grade[num] / max) * 100;
		sum += grade[num];
	}
	printf("%f", sum/N);
}