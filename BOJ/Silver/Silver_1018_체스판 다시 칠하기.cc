#include <iostream>

int main(void) {
	int horizontal, vertical, different_X, different_Y, test_result = 0, result = -1;
	char matrix[50][51];
	char test_case[2][8][8] = { { { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } } ,
				           		{ { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
							      { 'B','W','B','W','B','W','B','W' } ,
							      { 'W','B','W','B','W','B','W','B' } ,
						       	  { 'B','W','B','W','B','W','B','W' } ,
						       	  { 'W','B','W','B','W','B','W','B' } } };
	scanf("%d %d", &horizontal, &vertical);
	for (int Y = 0; Y < horizontal; Y++)
		scanf("%s", matrix[Y]);
	different_X = vertical - 8;
	different_Y = horizontal - 8;
	for (int test = 0; test < 2; test++) {
		for (int index_Y = 0; index_Y <= different_Y; index_Y++) {
			for (int index_X = 0; index_X <= different_X; index_X++) {
				for (int Y = index_Y, test_Y = 0; Y < index_Y + 8; Y++, test_Y++)
					for (int X = index_X, test_X = 0; X < index_X + 8; X++, test_X++)
						if (matrix[Y][X] != test_case[test][test_Y][test_X])
							test_result++;
				if (result == -1 || result > test_result) result = test_result;
				test_result = 0;
			}
		}
	}
	printf("%d", result);
	return 0;
}