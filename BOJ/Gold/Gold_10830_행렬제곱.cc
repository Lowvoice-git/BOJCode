#include <iostream>
#include <vector>
#include <string>
#include <bitset>

typedef long long LL;
typedef std::vector<std::vector<LL>> VECTOR;
LL N, mod;

VECTOR multpleMatrix(VECTOR A, VECTOR B) {
	int length = A.size();
	VECTOR result(length, std::vector<LL>(length));

	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < length; k++)
				result[i][j] += A[i][k] * B[k][j];
			result[i][j] %= 1000;
		}

	return result;
}

VECTOR powMatrix(VECTOR matrix) {
	int length = matrix.size();
	VECTOR result(length, std::vector<LL>(length));

	for (int i = 0; i < length; i++)
		result[i][i] = 1;

	while (mod > 0) {
		if (mod % 2 == 1)
			result = multpleMatrix(result, matrix);

		mod /= 2;
		matrix = multpleMatrix(matrix, matrix);
	}

	return result;
}

int main() {
	std::cin >> N >> mod;
	VECTOR matrix = VECTOR(N, std::vector<LL>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> matrix[i][j];

	matrix = powMatrix(matrix);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}
}