#include <iostream>
#include <vector>
#include <algorithm>

int N, C;
std::vector<int> Vector;

bool check(int distance) {
	int count = 1;
	int previous = Vector[0];
	for (int i = 1; i < N; i++)
		if (Vector[i] - previous >= distance) {
			previous = Vector[i];
			count++;
		}
	if (count >= C) return true;
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	std::cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
	}

	std::sort(Vector.begin(), Vector.end());

	int begin = 1, end = Vector.back() - Vector.front(), result = 0;
	while (begin <= end) {
		int middle = (begin + end) / 2;
		if (check(middle)) {
			result = std::max(result, middle);
			begin = middle + 1;
		}
		else end = middle - 1;
	}
	std::cout << result << '\n';
}