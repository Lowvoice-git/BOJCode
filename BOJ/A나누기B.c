#include<stdio.h>
int main(void) {
	double num1 = 0;
	double num2 = 0;
	scanf("%lf %lf", &num1, &num2);
	printf("%0.15lf", num1 / num2);
	return 0;
}