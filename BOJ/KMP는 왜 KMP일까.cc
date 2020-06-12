#include <iostream>
#include <string>

int main(void) {
	std::string name;
	std::string result;
	std::cin >> name;
	for (int num = 0; num < name.length(); num++)
		if (name[num] >= 65 && name[num] <= 90)
			result.push_back(name[num]);
	std::cout << result;
}