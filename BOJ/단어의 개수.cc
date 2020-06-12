#include <stdio.h>
#include <string.h>

char string[10000001];
int result = 0;

int function(int num) {
	for (int number = num; number<strlen(string); number++) {
		if (string[number] == ' ')
			result++;
	}
	return result++;
}

int main(void) {
	gets(string);
	if (string[0] == ' ') function(1);
	else function(0);
	if (string[strlen(string)-1] == ' ') result--;
	printf("%d", result);
}