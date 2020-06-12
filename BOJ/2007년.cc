#include <cstdio>

int main(void) {
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int month, year;
	int result = 0;

	scanf("%d %d", &year, &month);
	for (int num = 1; num <= year; num++) {
		for (int num2 = 1; num2 <= days[num]; num2++, result++) {
			result %= 7;
			if (num == year && num2 == month)
				break;
		}
	}
	switch (result) {
	case 0: printf("MON"); break;
	case 1: printf("TUE"); break;
	case 2: printf("WED"); break;
	case 3: printf("THU"); break;
	case 4: printf("FRI"); break;
	case 5: printf("SAT"); break;
	case 6: printf("SUN"); break;
	default:
		break;
	}
}