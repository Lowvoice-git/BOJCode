#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	std::vector<std::pair<int, int>> A;
	for (int i = 1; i <= 9; i++) {
		int temp; std::cin >> temp;
		A.push_back(std::make_pair(temp, i));
	}
	std::sort(A.begin(), A.end());
	std::cout << A[8].first << ' ' << A[8].second;
}