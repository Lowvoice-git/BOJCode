#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<std::pair<int, std::string>, int> PAIR;

std::vector<PAIR> point;

bool compare(const PAIR& A, const PAIR& B) {
	if (A.first.first == B.first.first)
		return A.second < B.second;

	return A.first.first < B.first.first;
}

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int A; std::string B; std::cin >> A >> B;
		point.push_back(std::make_pair(std::make_pair(A, B),i));
	}
	std::sort(point.begin(), point.end(), compare);

	for (auto iter : point)
		std::cout << iter.first.first << ' ' << iter.first.second << '\n';
}