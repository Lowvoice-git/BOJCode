#include <iostream>
#include <algorithm>

int main(void) {
	int x, y, w, h, result;
	int MIN_x, MIN_y;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	MIN_x = w - x; MIN_y = h - y;
	MIN_x = std::min(MIN_x, x);
	MIN_y = std::min(MIN_y, y);
	result = std::min(MIN_x, MIN_y);
	printf("%d", result);
	return 0;
}