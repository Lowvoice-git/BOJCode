#include <iostream>
#include <string>

int main() {
	bool check = true;
	std::string sequence, number = "";
	int result = 0;
	std::cin >> sequence;

	for (char ch : sequence) {
		if (ch == '-') {
			if (check) result += std::stoi(number);
			else result -= std::stoi(number);
			check = false;
			number.clear();
		}
		else if (ch == '+') {
			if (check) result += std::stoi(number);
			else result -= std::stoi(number);
			number.clear();
		}
		else number += ch;
	}

	if (check) result += std::stoi(number);
	else result -= std::stoi(number);

	std::cout << result;
}