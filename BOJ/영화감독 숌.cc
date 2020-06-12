#include <stdio.h>
int Array[10] = { 0,0,0,0,0,0,0,6,6,6 };

void digitUp(int index) {
	if (Array[index] == 9) {
		Array[index] = 0;
		digitUp(index - 1);
	}
	else Array[index]++;
}

int main(void) {
	int N;
	scanf("%d", &N);
	while (true) {
		for (size_t num = 9; num >= 2; --num)
			if (Array[num] == 6 && Array[num - 1] == 6 && Array[num - 2] == 6) {
				N--;
				break;
			}
		if (N == 0) {
			bool temp = false;
			for (size_t num = 0; num < 10; num++) {
				if (!temp) {
					if (Array[num] == 0) continue;
					else {
						temp = true;
						printf("%d", Array[num]);
					}
				}
				else printf("%d", Array[num]);
			}
			break;
		}
		else digitUp(9);
	}
	return 0;
}