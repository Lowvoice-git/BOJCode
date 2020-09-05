#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> PAIR;
std::vector<PAIR> Array, Stack;

bool compare(const PAIR& A, const PAIR& B) {
	if (A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B; std::cin >> A >> B;
		Array.push_back({ A,B });
	}

	std::sort(Array.begin(), Array.end(), compare);

	Stack.push_back(Array[0]);

	for (int i = 1; i < N; i++)
		if (Stack.back().second <= Array[i].first)
			Stack.push_back(Array[i]);

	std::cout << Stack.size();
}