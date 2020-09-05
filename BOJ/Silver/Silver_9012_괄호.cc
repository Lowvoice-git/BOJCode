#include <stdio.h>
#include <string.h>
int main()
{
	char line[51];
	char stack[51];
	int line_count;

	scanf("%d", &line_count);
	for (int _num = 0; _num< line_count; _num++) {
		int result = 0;
		scanf("%s", line);

		if (line[0] == ')') {
			printf("NO\n");
			continue;
		}
		for (int __num = 0; __num<strlen(line); __num++) {
			if (line[__num] == '(') {
				stack[__num] = '(';
				result++;
			}
			else if (line[__num] == ')') {
				stack[__num - 1] = 0;
				result--;
				if (result<0) 
					break;
			}
		}
		if (result == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}