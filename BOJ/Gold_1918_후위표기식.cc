#include <iostream>
#include <string>
#include <stack>

std::stack<char> Stack;

int Proceed(char op) {
	switch (op) {
	case '*':
	case '/': return 3;
	case '+':
	case '-': return 2;
	case '(': return 1;
	default: return 0;
	}
}

int main() {
	std::string infix_notation, result;
	std::cin >> infix_notation;

	for (int num = 0; num < infix_notation.size(); num++) {
		if (infix_notation[num] >= 'A' && infix_notation[num] <= 'Z')
			result += infix_notation[num];
		else {
			switch (infix_notation[num]) {
			case '(':
				Stack.push(infix_notation[num]);
				break;
			case ')': 
				while (true) {
					if (Stack.top() == '(') {
						Stack.pop();
						break;
					}
					result += Stack.top();
					Stack.pop();
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!Stack.empty() && (Proceed(Stack.top()) >= Proceed(infix_notation[num])) ? true : false) {
					result += Stack.top(); Stack.pop();
				}
				Stack.push(infix_notation[num]);
				break;
			default: break;
			}
		}
	}
	while (!Stack.empty()) {
		result += Stack.top(); Stack.pop();
	}

	std::cout << result;
}