#include <stdio.h>
#include <stdlib.h>

#define UP	-1
#define DOWN	1
#define LEFT	-1
#define RIGHT	1
#define POSE	0

char map[51][51];

int X_direction[8] = { LEFT, LEFT, LEFT, POSE, RIGHT, RIGHT, RIGHT, POSE };
int Y_direction[8] = { UP	, POSE, DOWN, DOWN, DOWN , POSE , UP  , UP };

void BFS_map(int, int);
int main(void) {
	int vertical; int horizontal;

	while (true) {
		char **input_map; int count = 0;
		scanf("%d %d", &vertical, &horizontal); while (getchar() != '\n');
		if (vertical == 0 && horizontal == 0)
			break;

		input_map = (char**)calloc(horizontal, sizeof(char*));
		for (int Y = 0; Y < horizontal; Y++) {
			input_map[Y] = (char*)calloc(2 * vertical, sizeof(char));
			gets(input_map[Y]);
		}
		int Y2; int X2;
		for (int Y = 0, Y2 = 1; Y < horizontal; Y++) {
			for (int X = 0, X2 = 1; X < 2 * vertical; X++) 
				if (input_map[Y][X] != ' ')
					map[Y2][X2++] = input_map[Y][X];
			Y2++;
		}

		for (int Y = 1; Y <= horizontal; Y++)
			for (int X = 1; X <= vertical; X++)
				if (map[Y][X] == '1') {
					count++;
					BFS_map(X, Y);
				}

		printf("%d\n", count);

	}

	return 0;
}

void BFS_map(int vertical, int horizontal) {
	int _vertical; int _horizontal;
	map[horizontal][vertical] = '0';
	for (int direction = 0; direction < 8; direction++) {
		_vertical		= vertical + X_direction[direction];
		_horizontal	= horizontal + Y_direction[direction];

		if (map[_horizontal][_vertical] == '1')
			BFS_map(_vertical, _horizontal);
	}
}