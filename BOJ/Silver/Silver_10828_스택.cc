#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int stack[10001];

int main() {
	char orders[10000][11]; int orders_count; int result[10000]; int count = 0;
		scanf("%d", &orders_count); while (getchar() != '\n');

	for (int _num = 0; _num < orders_count; _num++) {
		gets(orders[_num]);
	}

	for (int _num = 0; _num < orders_count; _num++) {
		if (!strncmp(orders[_num], "push", 4)) 
			stack[++top] = atoi(orders[_num] + 5);
		
		else if (!strcmp(orders[_num], "pop")) {
			if (top == -1) result[count++] = top;
			else result[count++] = stack[top--];
		}
		else if (!strcmp(orders[_num], "empty")) {
			if (top == -1)
				result[count++] = 1;
			else
				result[count++] = 0;
		}
		else if (!strcmp(orders[_num], "top")) {
			if (top == -1) result[count++] = top;
			else	 result[count++] = stack[top];
		}
		else if (!strcmp(orders[_num], "size")) 
			result[count++] = top + 1;
	}

	for (int _num = 0; _num < count; _num++)
		printf("%d\n", result[_num]);

	return 0;
}

