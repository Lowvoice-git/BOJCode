#include <iostream>
#include <string>

int main() {
	std::string text1, text2;
	std::cin >> text1 >> text2;
	if (text1.length() < text2.length()) std::cout << "no";
	else std::cout << "go";
}