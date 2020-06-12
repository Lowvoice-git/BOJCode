#include <vector>
#include <queue>
#include <cstdio>
#define MAX_SIZE 10
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1

using namespace std;
class Current_Board_state {
public:
	int count, Rx, Ry, Bx, By;
public:
	Current_Board_state() {
		count = 0;
		Rx = 0; Ry = 0;
		Bx = 0; By = 0;
	}
	Current_Board_state(int count, int Rx, int Ry, int Bx, int By) {
		this->count = count;
		this->Rx = Rx; this->Ry = Ry;
		this->Bx = Bx; this->By = By;
	}
};
typedef struct Location_of_R {
	int x; int y;
} R;
typedef struct Location_of_B {
	int x; int y;
} B;
typedef struct Location_of_O {
	int x; int y;
} O;

int horizontal, vertical;
int x_direction[4] = { LEFT,RIGHT,0,0 };
int y_direction[4] = { 0,0,UP,DOWN };
char matrix[MAX_SIZE][MAX_SIZE+1];

int print(int);

int main() {
	int result = -1;
	R R; B B; O O;

	scanf("%d%d", &vertical, &horizontal);

	for (int i = 0; i < vertical; i++)
		scanf("%s", matrix[i]);
	for (int x = 0; x < vertical; x++) {
		for (int y = 0; y < horizontal; y++) {
			if (matrix[x][y] == 'R')
				R.x = x, R.y = y;
			else if (matrix[x][y] == 'B')
				B.x = x, B.y = y;
			else if (matrix[x][y] == 'O')
				O.x = x, O.y = y;
		}
	}
	queue<Current_Board_state> Queue;
	Queue.push(Current_Board_state(0, R.x, R.y, B.x, B.y));
	while (!Queue.empty()) {
		Current_Board_state CBs;
		CBs.count = Queue.front().count;
		CBs.Rx = Queue.front().Rx;
		CBs.Ry = Queue.front().Ry;
		CBs.Bx = Queue.front().Bx;
		CBs.By = Queue.front().By;
		Queue.pop();

		if (CBs.count == 10)
			break;
		for (int i = 0; i < 4; i++) {
			int Red_ball_Exit = 0;
			int meet_Blue_ball = 0;
			int move_Rx, move_Ry;
			int Red_ball_moved = 0;
			move_Rx = CBs.Rx + x_direction[i];
			move_Ry = CBs.Ry + y_direction[i];
			while (matrix[move_Rx][move_Ry] != '#') {
				Red_ball_moved++;
				if (move_Rx == CBs.Bx && move_Ry == CBs.By)
					meet_Blue_ball = Red_ball_moved;
				if (matrix[move_Rx][move_Ry] == 'O')
					Red_ball_Exit = Red_ball_moved;
				move_Rx += x_direction[i];
				move_Ry += y_direction[i];
			}
			bool Blue_ball_Exit = false;
			bool meet_Red_ball = false;
			int move_Bx, move_By;
			int Blue_ball_moved = 0;
			move_Bx = CBs.Bx + x_direction[i];
			move_By = CBs.By + y_direction[i];
			while (matrix[move_Bx][move_By] != '#') {
				Blue_ball_moved++;
				if (move_Bx == CBs.Rx&&move_By == CBs.Ry)
					meet_Red_ball = true;
				if (matrix[move_Bx][move_By] == 'O')
					Blue_ball_Exit = true;
				move_Bx += x_direction[i];
				move_By += y_direction[i];
			}
			if (!meet_Blue_ball && !meet_Red_ball) {
				if (Red_ball_Exit) {
					result = CBs.count + 1;
					print(result);
					return 0;
				}
				else if (Blue_ball_Exit)
					continue;
				else {
					Queue.push(Current_Board_state(
						CBs.count + 1,
						CBs.Rx + x_direction[i] * Red_ball_moved,
						CBs.Ry + y_direction[i] * Red_ball_moved,
						CBs.Bx + x_direction[i] * Blue_ball_moved,
						CBs.By + y_direction[i] * Blue_ball_moved
					));
				}
			}
			else if (meet_Blue_ball) {
				if (Red_ball_Exit) {
					if (Red_ball_Exit<meet_Blue_ball) {
						result = CBs.count + 1;
						print(result);
						return 0;
					}
					continue;
				}
				else {
					Red_ball_moved--;
					Queue.push(Current_Board_state(
						CBs.count + 1,
						CBs.Rx + x_direction[i] * Red_ball_moved,
						CBs.Ry + y_direction[i] * Red_ball_moved,
						CBs.Bx + x_direction[i] * Blue_ball_moved,
						CBs.By + y_direction[i] * Blue_ball_moved
					));
				}
			}
			else {
				if (Red_ball_Exit)
					continue;
				else {
					Blue_ball_moved--;
					Queue.push(Current_Board_state(
						CBs.count + 1,
						CBs.Rx + x_direction[i] * Red_ball_moved,
						CBs.Ry + y_direction[i] * Red_ball_moved,
						CBs.Bx + x_direction[i] * Blue_ball_moved,
						CBs.By + y_direction[i] * Blue_ball_moved
					));
				}
			}
		}
	}
	print(result);
	return 0;
}

int print(int result) {
	printf("%d\n", result);
	return 0;
}