#include <iostream>
#include <stack>
#include <string>

std::stack<char> line;

int main(void) {
	std::string sequence; int count = 0, result = 0;
	std::cin >> sequence;
	for (int num = 0; num < sequence.length() - 1; num++) {
		if (sequence[num] == '(' && sequence[num + 1] == ')') {
			sequence.replace(num, 2, "*");
		}
	}
	for (int num = 0; num < sequence.length(); num++) {
		if (sequence[num] == '(') {
			line.push(sequence[num]);
			count++;
		}
		else if (sequence[num] == ')') {
			line.pop();
			count--; result++;
		}
		else {
			result += count;
		}
		if (line.empty()) count = 0;
	}
	printf("%d", result);
}