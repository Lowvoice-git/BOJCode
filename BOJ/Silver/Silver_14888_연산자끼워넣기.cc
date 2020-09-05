#include <iostream>
#include <limits.h>

bool visited[10];
int N, number[11], op[10], max = INT_MIN, min = INT_MAX;

void DFS(int B, int idx, int num, int lengh) {
	int result = 0;

	if (lengh == N - 1) {
		if (num > max) max = num;
		if (num < min) min = num;
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (!visited[i]) {
				switch (op[i]) {
				case 1: result = num + number[idx]; break;
				case 2: result = num - number[idx]; break;
				case 3: result = num * number[idx]; break;
				case 4: result = num / number[idx]; break;
				default: break;
				}
				visited[i] = true;
				DFS(i, idx + 1, result, lengh + 1);
			}
		}
	}

	visited[B] = false;
}

int main() {
	int index = 0; std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> number[i];

	for (int i = 0; i < 4; i++) {
		int count; std::cin >> count;
		for (int j = 0; j < count; j++)
			op[index++] = i + 1;
	}

	DFS(0, 1, number[0], 0);

	std::cout << max << '\n' << min;
}