#include <iostream>
#include <utility>

typedef std::pair<int, int> PAIR;

int matrix[129][129];
PAIR result;

void checkMatrix(int length, PAIR position) {
	std::pair<bool, bool> check;
	if (matrix[position.first][position.second] == 1) {
		check.first = true; check.second = false;
		for (int i = position.first; i < position.first + length; i++) {
			if (check.first == false)
				break;
			for (int j = position.second; j < position.second + length; j++)
				if (matrix[i][j] != 1) {
					check.first = false;
					break;
				}
		}
	}
	else {
		check.first = false; check.second = true;
		for (int i = position.first; i < position.first + length; i++) {
			if (check.second == false)
				break;
			for (int j = position.second; j < position.second + length; j++)
				if (matrix[i][j] != 0) {
					check.second = false;
					break;
				}
		}
	}

	if (check.first) result.first++;
	else if (check.second) result.second++;
	else {
		checkMatrix(length / 2, position);
		checkMatrix(length / 2, { position.first + length / 2,position.second });
		checkMatrix(length / 2, { position.first,position.second + length / 2 });
		checkMatrix(length / 2, { position.first + length / 2,position.second + length / 2 });
	}
}

int main() {
	int N; std::cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			std::cin >> matrix[i][j];
	checkMatrix(N, {1,1});
	std::cout << result.second << '\n' << result.first;
}