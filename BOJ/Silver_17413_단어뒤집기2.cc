#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

std::stack<std::string> Stack;

int main() {
	bool check = false; std::string section, result;
	std::getline(std::cin, section);
	for (int num = 0; num < section.size(); num++) {
		switch (section[num]) {
		case '<':
			check = true;
			std::reverse(result.begin(), result.end());
			std::cout << result;
			result.clear();
			result += '<';
			break;
		case '>':
			check = false;
			std::cout << result << '>';
			result.clear();
			break;
		case ' ': 
			if (check)
				result += ' ';
			else {
				std::reverse(result.begin(), result.end());
				std::cout << result << ' '; result.clear();
			}
			break;
		default:
			result += section[num]; break;
		}
	}
	std::reverse(result.begin(), result.end());
	std::cout << result;
}