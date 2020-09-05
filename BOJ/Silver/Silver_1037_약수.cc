#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> numbers;

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		numbers.push_back(temp);
	}

	std::sort(numbers.begin(), numbers.end());

	if (numbers.size() == 1) std::cout << numbers[0] * numbers[0];
	else std::cout << numbers.front() * numbers.back();
}