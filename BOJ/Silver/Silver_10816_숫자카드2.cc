#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Vector;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int N,T;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
	}
	std::sort(Vector.begin(), Vector.end());
	std::cin >> T;
	while (T--) {
		int temp; std::cin >> temp;
		int begin = std::lower_bound(Vector.begin(), Vector.end(), temp)-Vector.begin()+1;
		int end = std::upper_bound(Vector.begin(), Vector.end(), temp) - Vector.begin() + 1;
		std::cout << end - begin << ' ';
	}
}