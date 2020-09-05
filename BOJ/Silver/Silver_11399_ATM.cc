#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sequence;
int main() {
	int n, result = 0;
	std::cin >> n;
	std::vector<int> temp(n);
	for (int num = 0; num < n; num++) {
		int temp; std::cin >> temp;
		sequence.push_back(temp);
	}
	std::sort(sequence.begin(), sequence.end());
	for (int num1 = 0; num1 < sequence.size(); num1++) {
		for (int num2 = num1; num2 < sequence.size(); num2++)
			temp[num2] += sequence[num1];
		result += temp[num1];
	}
	std::cout << result;
}