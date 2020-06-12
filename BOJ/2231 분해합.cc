#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int compare, result; std::string N;
	std::cin >> N;
	result = compare = std::stoi(N);
	for (int i = 1; i <= std::stoi(N); i++) {
		int sum = 0;
		std::string temp = std::to_string(i);
		for (int j = 0; j < temp.length(); j++)
			sum += temp[j] - '0';
		sum += std::stoi(temp);

		if (sum == compare)
			result = std::min(result, i);
	}
	if (result == compare) std::cout << 0;
	else std::cout << result;
}