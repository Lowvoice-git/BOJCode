#include <iostream>
#include <cmath>

int N, column[15], result = 0;

bool check(int index) {
	for (int num = 0; num < index; num++)
		if (column[num] == column[index] || std::abs(column[index] - column[num]) == (index - num))
			return false;
	return true;
}

void DFS(int index) {
	if (index == N) result++;
	else
		for (int num = 0; num < N; num++) {
			column[index] = num;
			if (check(index)) DFS(index + 1);
		}
}

int main() {
	std::cin >> N;
	DFS(0);
	std::cout << result;
}