#include <iostream>
#include <vector>
#include <stack>

std::vector<int> numbers, result;
std::stack<int> Stack;

int main() {
	int N; std::cin >> N;
	result = std::vector<int>(N, -1);
	for (int num = 0; num < N; num++) {
		int temp; std::cin >> temp;
		numbers.push_back(temp);
	}
	for (int num = 0; num < N; num++) {
		while (!Stack.empty() && numbers[Stack.top()] < numbers[num]) {
			result[Stack.top()] = numbers[num];
			Stack.pop();
		}
		Stack.push(num);
	}
	for (int num = 0; num < N; num++)
		std::cout << result[num] << ' ';
}