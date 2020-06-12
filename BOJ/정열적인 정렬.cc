#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vector;

int main() {
	int n;
	std::cin >> n;
	for (int num = 0; num < n; num++) {
		int temp; std::cin >> temp;
		vector.push_back(temp);
	}
	std::sort(vector.begin(), vector.end());
	for (int num = 0; num < n; num++)
		std::cout << vector[num] << ' ';
}