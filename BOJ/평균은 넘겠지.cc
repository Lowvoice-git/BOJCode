#include <cstdio>
#include <algorithm>

int main(void) {
	int N, M, sum = 0, count;
	int grade[1000];
	double avg = 0;
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		scanf("%d", &M);
		for (int num2 = 0; num2 < M; num2++) {
			scanf("%d", &grade[num2]);
			sum += grade[num2];
		}
		avg = sum / M; count = 0; sum = 0;
		for (int num2 = 0; num2 < M; num2++) {
			if (avg < grade[num2])
				count++;
		}
		avg = (double)count / M;
		printf("%.3lf%%\n", avg * 100);
	}
}