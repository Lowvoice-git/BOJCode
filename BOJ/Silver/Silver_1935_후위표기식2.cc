#include <iostream>
#include <vector>
#include <stack>
#include <string>

std::vector<double> number;
std::stack<double> Stack;

int main() {
	int N; std::string expression;
	std::cin >> N >> expression;
	for (int num = 0; num < N; num++) {
		double temp; std::cin >> temp;
		number.push_back(temp);
	}
	for (int num = 0; num < expression.size(); num++) {
		if (expression[num] >= 'A' && expression[num] <= 'Z')
			Stack.push(number[expression[num] - 'A']);
		else {
			double A = Stack.top(); Stack.pop();
			double B = Stack.top(); Stack.pop();
			switch (expression[num]) {
			case '+': Stack.push(B + A); break;
			case '-': Stack.push(B - A); break;
			case '*': Stack.push(B * A); break;
			case '/': Stack.push(B / A); break;
			default: break;
			}
		}
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << Stack.top();
}