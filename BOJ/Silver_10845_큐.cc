#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front= -1;
int rear	= -1;
int queue[10000];

int main() {
	char orders[10000][11]; int orders_count; int result[10000]; int count = 0;
	scanf("%d", &orders_count); while (getchar() != '\n');

	for (int _num = 0; _num < orders_count; _num++) {
		gets(orders[_num]);
	}

	for (int _num = 0; _num < orders_count; _num++) {
		if (!strncmp(orders[_num], "push", 4))
			queue[++rear] = atoi(orders[_num] + 5);

		else if (!strcmp(orders[_num], "pop")) {
			if (front == rear) 
                result[count++] = -1;
			else 
                result[count++] = queue[++front];
		}
		else if (!strcmp(orders[_num], "empty")) {
			if (front == rear)
				result[count++] = 1;
			else
				result[count++] = 0;
		}
		else if (!strcmp(orders[_num], "front")) {
			if (front == rear) 
                result[count++] = -1;
			else	 
                result[count++] = queue[front+1];
		}
		else if (!strcmp(orders[_num], "back")) {
			if (front == rear) 
                result[count++] = -1;
			else	 
                result[count++] = queue[rear];
		}
		else if (!strcmp(orders[_num], "size"))
			result[count++] = (rear - front);
	}

	for (int _num = 0; _num < count; _num++)
		printf("%d\n", result[_num]);

	return 0;
}