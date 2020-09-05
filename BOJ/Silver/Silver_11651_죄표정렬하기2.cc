#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> PAIR;

std::vector<PAIR> point;

bool compare(const PAIR& A, const PAIR& B) {
	if (A.second == B.second)
		return A.first < B.first;

	return A.second < B.second;
}

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B; std::cin >> A >> B;
		point.push_back(std::make_pair(A, B));
	}
	std::sort(point.begin(), point.end(), compare);

	for (auto iter : point)
		std::cout << iter.first << ' ' << iter.second << '\n';
}