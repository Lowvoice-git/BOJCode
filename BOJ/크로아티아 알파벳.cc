#include <stdio.h>
#include <string.h>

int main(void) {
	char alphabet[10][4] = { "c=","c-","dz=","d-","lj","nj","s=","z=","=","-" };
	char line[101];
	scanf("%s", line);
	int count = 0, result = strlen(line);
	for (int num = 0; num < 10; num++) {
		char *ptr = line;
		while (ptr != NULL) {
			ptr = strstr(ptr, alphabet[num]);
			if (ptr != NULL) {
				if (num == 2) {
					count += 2;
					*ptr = '*'; *(ptr + 1) = '*'; *(ptr + 2) = '*';
				}
				else {
					count++;
					*ptr = '*'; *(ptr + 1) = '*';
				}
			}
			else ptr = NULL;
		}
		result -= count; count = 0;
	}
	printf("%d", result);
}