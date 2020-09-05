#include <iostream>
#include <stack>

std::stack<int> Stack;

int main(void) {
	int N, result = 0; scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		int number; scanf("%d", &number);
		if (number) Stack.push(number);
		else Stack.pop();
	}
	while (!Stack.empty()) {
		result += Stack.top();
		Stack.pop();
	}
	printf("%d", result);
}