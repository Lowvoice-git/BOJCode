#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Vector;

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
	}
	int index = 0;
	for (int e : Vector) {
		auto position = std::lower_bound(Vector.begin(), Vector.begin() + index, e);
		*position = e;
		if (position == Vector.begin() + index) index++;
	}
	std::cout << index;
}