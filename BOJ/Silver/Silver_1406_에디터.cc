#include <iostream>
#include <string>
#include <list>
#include <iterator>

int main() {
	std::string text; int N;
	std::cin >> text >> N;
	std::list<char> list(text.begin(),text.end());
	std::list<char>::iterator iter = list.end();
	while (N--) {
		char temp; std::cin >> temp;
		switch (temp) {
		case 'L':
			if (iter != list.begin()) iter--;
			break;
		case 'D':
			if (iter != list.end()) iter++;
			break;
		case 'B':
			if (iter != list.begin())
				iter = list.erase(--iter);
			break;
		case 'P':
			char character;
			std::cin >> character;
			list.insert(iter, character);
			break;
		default:
			break;
		}
	}
	for (auto& it : list) std::cout << it;
}