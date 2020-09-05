#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

std::vector<std::pair<std::string, int>> Array;

bool compare(const std::pair<std::string, int> &left, const std::pair<std::string, int> &right) {
	if (left.second < right.second) return true;
	else if (left.second == right.second) return left.first < right.first;
	else return false;
}

int main(void) {
	int N; std::cin.tie(NULL); std::ios::sync_with_stdio(false);
	std::cin >> N;
	for (int num = 0; num < N; num++) {
		std::string word;
		std::cin >> word;
		Array.push_back(std::make_pair(word, word.length()));
	}
	std::stable_sort(Array.begin(), Array.end(), compare);
	Array.erase(std::unique(Array.begin(), Array.end()), Array.end());
	for (auto it = Array.begin(); it != Array.end(); it++)
		std::cout << (*it).first << '\n';
}