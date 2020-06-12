#include <stdio.h>

void function(int n, int m) {
	if (n <= 0) return;
	for (int num = 0; num < n - 1; num++)
		printf(" ");
	for (int num = 0; num < m; num++)
		printf("*");
	printf("\n");
	function(n - 1, m + 2);
}

int main() {
	int n;
	scanf("%d", &n);
	function(n, 1);
}