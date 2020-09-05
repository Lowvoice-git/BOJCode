#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

std::vector<std::pair<int, int>> Array;

bool compare(const std::pair<int, int> &left, const std::pair<int, int> &right) {
	if (left.first < right.first) return true;
	else if (left.first == right.first) return left.second < right.second;
	else return false;
}

int main(void) {
	int N; std::cin.tie(NULL); std::ios::sync_with_stdio(false);
	std::cin >> N;
	for (int num = 0; num < N; num++) {
		int X, Y;
		std::cin >> X >> Y;
		Array.push_back(std::make_pair(X, Y));
	}
	std::stable_sort(Array.begin(), Array.end(), compare);
	for (auto it = Array.begin(); it != Array.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\n';
}