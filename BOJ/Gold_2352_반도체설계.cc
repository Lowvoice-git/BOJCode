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
	for (int i : Vector) {
		auto position = std::lower_bound(Vector.begin(), Vector.begin() + index, i);
		*position = i;
		if (position == Vector.begin() + index)
			index++;
	}
	std::cout << index;
}