#include <iostream>
#include <algorithm>

int A[100000];
int M[100000];

int main(void) {
	int N, nM;
	scanf("%d", &N);
	for (int num = 0; num < N; num++)
		scanf("%d", &A[num]);
	std::sort(A, A + N);
	scanf("%d", &nM);
	for (int num = 0; num < nM; num++) {
		scanf("%d", &M[num]);
		printf("%d\n", std::binary_search(A, A + N, M[num]));
	}
	return 0;
}