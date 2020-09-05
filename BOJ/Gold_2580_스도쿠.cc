#include <iostream>

int matrix[9][9];
bool column[9][9];
bool row[9][9];
bool check[9][9];

void DFS(int level) {
	int x = level / 9;
	int y = level % 9;

	if (level == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		exit(0);
	}

	if (!matrix[x][y]) {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !column[y][i] && !check[(x / 3) * 3 + (y / 3)][i]) {
				row[x][i] = column[y][i] = check[(x / 3) * 3 + (y / 3)][i] = true;
				matrix[x][y] = i;
				DFS(level + 1);
				matrix[x][y] = 0;
				row[x][i] = column[y][i] = check[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	else DFS(level + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> matrix[i][j];
			if (matrix[i][j] != 0) {
				row[i][matrix[i][j]] = true;
				column[j][matrix[i][j]] = true;
				check[(i / 3) * 3 + (j / 3)][matrix[i][j]] = true;
			}
		}
	}

	DFS(0);
}