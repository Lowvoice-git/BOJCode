#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Vector;

int main() {
	int N; std::cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
	}
	std::sort(Vector.begin(), Vector.end());

	for (int i = 0; i < N; i++) {
		if (Vector[i] <= result + 1) result += Vector[i];
		else break;
	}
	std::cout << result + 1;
}