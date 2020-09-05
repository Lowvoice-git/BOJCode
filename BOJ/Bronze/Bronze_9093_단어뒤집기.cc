#include <iostream>
#include <algorithm>
#include <string>

int main() {
	int T; std::cin >> T; std::string buffer;
	std::getline(std::cin, buffer);
	while (T--) {
		std::string section, temp, result;
		std::getline(std::cin, section);
		for (int num = 0; num < section.size(); num++)
			if (section[num] == ' ') {
				std::reverse(temp.begin(), temp.end());
				std::cout << temp << ' ';
				temp.clear();
			}
			else temp += section[num];
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << '\n';
	}
}