#include <iostream>
#include <vector>
#include <stack>
#include <climits>

int count[1000001];
std::vector<int> numbers, result;
std::stack<int> Stack;

int main() {
	int N; std::cin >> N;
	numbers.resize(N); result.resize(N);
	count[0] = INT_MAX; Stack.push(0);
	for (int num = 0; num < N; num++) {
		std::cin >> numbers[num];
		count[numbers[num]]++;
	}
	for (int num = N - 1; num >= 0; num--) {
		while (count[Stack.top()] <= count[numbers[num]]) Stack.pop();
		if (count[Stack.top()] > INT_MAX - 1) result[num] = -1;
		else result[num] = Stack.top();
		Stack.push(numbers[num]);
	}
	for (int num = 0; num < N; num++)
		std::cout << result[num] << ' ';
}