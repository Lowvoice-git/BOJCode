#include <stdio.h>
#include <stdlib.h>
#define SWAP(value1,value2,type) do {	\
	type temp;		        			\
	temp	= value1;		    		\
	value1	= value2;			    	\
	value2	= temp;					    \
} while(false)

static int *vector;

int main(void) {
	int number; int _num;
	scanf("%d", &number);

	vector = (int*)calloc(number, sizeof(int));

	for (_num = 0; _num < number; _num++)
		scanf("%d", &vector[_num]);

	for (int num1 = 1; num1 < number; num1++) {
		for (int num2 = 0; num2 < number; num2++) {
			if (vector[num1] < vector[num2])
				SWAP(vector[num1], vector[num2], int);
		}
	}
	
	for (_num = 0; _num < number; _num++)
		printf("%d\n", vector[_num]);
	return 0;
}