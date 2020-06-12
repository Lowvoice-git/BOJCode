#include <iostream>
#include <vector>
#include <string>

int matrix[1001][1001];

int main() {
	std::string A, B, result;
	std::cin >> A >> B;
	A = '0' + A; B = '0' + B;
	for (int Y = 0; Y < B.length(); Y++) {
		for (int X = 0; X < A.length(); X++) {
			if (Y == 0 || X == 0) continue;
			if (A[X] == B[Y]) matrix[Y][X] = matrix[Y - 1][X - 1] + 1;
			else {
				if (matrix[Y - 1][X] > matrix[Y][X - 1])
					matrix[Y][X] = matrix[Y - 1][X];
				else matrix[Y][X] = matrix[Y][X - 1];
			}
		}
	}
	
	std::cout << matrix[B.length() - 1][A.length() - 1];
}