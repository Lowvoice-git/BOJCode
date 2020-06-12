#include <iostream>
#include <stack>
#include <string>

int main(void) {
	while (true) {
		std::string text; std::stack<char> line; bool check = true; int count1 = 0, count2 = 0;
		std::getline(std::cin, text);
		if (text.length() == 1 && text[0] == '.') break;
		for (int num = 0; text[num] != '.'; num++) {
			if (text[num] == '(' || text[num] == '[') line.push(text[num]);
			else if (text[num] == ')') {
				count1++;
				if (!line.empty())
					if (line.top() == '(') {
						line.pop(); count1--;
					}
			}
			else if (text[num] == ']') {
				count2++;
				if (!line.empty())
					if (line.top() == '[') {
						line.pop(); count2--;
					}
			}
		}
		if (line.empty()&&!count1&&!count2) printf("yes\n");
		else printf("no\n");
	}
}