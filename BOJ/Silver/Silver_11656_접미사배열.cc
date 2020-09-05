#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> Vector;

int main() {
	std::string S;
	std::cin >> S;
	while (!S.empty()) {
		Vector.push_back(S);
		S.erase(S.begin());
	}
	
	std::sort(Vector.begin(), Vector.end());

	for (int num = 0; num < Vector.size(); num++)
		std::cout << Vector[num] << '\n';
}