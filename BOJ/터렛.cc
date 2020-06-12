#include <stdio.h>

int main() {
	int n, x1, y1, x2, y2, r1, r2;
	scanf("%d", &n);
	for (int num = 0; num < n; num++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int distance = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) { printf("-1\n"); continue; }
			else { printf("0\n"); continue; }
		}
		else if (distance == (r1 + r2) * (r1 + r2) || distance == (r1 - r2) * (r1 - r2))
			printf("1\n");
		else if (distance < (r1 + r2) * (r1 + r2) && distance > (r1 - r2) * (r1 - r2))
			printf("2\n");
		else printf("0\n");
	}
}