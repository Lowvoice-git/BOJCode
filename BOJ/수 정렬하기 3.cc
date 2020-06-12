#include <stdio.h>

int count[10001];
int main() {
	int size; int value = 0;
	scanf("%d", &size);

	for (int _num = 0; _num < size; _num++) {
		scanf("%d", &value);
		count[value]++;
	}
	for (int _num = 1; _num <= 10000; _num++) {
		if (count[_num] > 0)
			for (int __num = 0; __num < count[_num]; __num++)
				printf("%d\n", _num);
	}
	return 0;
}