#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
int button[10];

int check(int number) {
	std::string str = std::to_string(number);
	int length = str.length();
	for (int num = 0; num < length; ++num)
		if (button[str[num] - '0'])
			return 0;
	return length;
}

int main(void) {
	int number, button_number, result = 0;
	scanf("%d %d", &number, &button_number);
	for (int num = 0; num < button_number; num++) {
		int temp;
		scanf("%d", &temp);
		button[temp] = 1;
	}
	result = abs(100 - number);
	for (int num = 0; num <= 1000000; ++num) {
		int length = check(num);
		if (length)
			result = std::min(abs(number - num) + length, result);
	}
	printf("%d", result);
	return 0;
}