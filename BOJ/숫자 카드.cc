#include <iostream>
#include <algorithm>

int N[500000];
int M[500000];

int main(void) {
	int n, m;
	scanf("%d", &n);
	for (int num = 0; num < n; num++)
		scanf("%d", &N[num]);
	std::sort(N, N + n);
	scanf("%d", &m);
	for (int num = 0; num < m; num++) 
		scanf("%d", &M[num]);
	for (int num = 0; num < m; num++)
		printf("%d ", std::binary_search(N, N + n, M[num]));
	return 0;
}