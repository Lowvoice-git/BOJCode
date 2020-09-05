#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> PAIR;

int memo[101];
std::vector<PAIR> sequence(1);

bool compare(const PAIR& A, const PAIR& B) {
	return A.first < B.first;
}

int main() {
	int N, result = 0; std::cin >> N;
	for (int i = 1; i <= N; i++) {
		int A, B; std::cin >> A >> B;
		sequence.push_back(std::make_pair(A, B));
		memo[i] = 1;
	}

	std::sort(sequence.begin(), sequence.end(), compare);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j < i; j++)
			if (sequence[i].second > sequence[j].second && memo[j] + 1 > memo[i])
				memo[i] = memo[j] + 1;

	for (int i = 1; i <= N; i++)
		result = std::max(result, memo[i]);

	std::cout << N - result;
}