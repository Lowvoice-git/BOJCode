#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<std::pair<int, int>> vector1;
std::vector<std::pair<int, int>> vector2;

bool compare(const std::pair<int,int> &A, const std::pair<int, int> &B) {
	return std::min(A.first, A.second) < std::min(B.first, B.second);
}

int main() {
	int N, M, quotient, remainder;
	std::cin >> N >> M;
	quotient = N / 6; remainder = N % 6;
	if (N > 6) {
		for (int num = 0; num < M; num++) {
			int first, second; std::cin >> first >> second;
			vector1.push_back(std::make_pair(first, second * 6));
			vector2.push_back(std::make_pair(first, second * remainder));
		}
		std::sort(vector1.begin(), vector1.end(), compare);
		std::sort(vector2.begin(), vector2.end(), compare);

		std::cout << std::min(vector1[0].first, vector1[0].second) * quotient + std::min(vector2[0].first, vector2[0].second);
	}
	else {
		for (int num = 0; num < M; num++) {
			int first, second; std::cin >> first >> second;
			vector1.push_back(std::make_pair(first, second * N));
		}
		std::sort(vector1.begin(), vector1.end(), compare);

		std::cout << std::min(vector1[0].first, vector1[0].second);
	}
}