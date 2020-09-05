#include <iostream>
#include <string>

int main() {
	std::string sequence;
	int n;
	std::cin >> n;
	for (int num = 0; num < n; num++) {
		std::cin >> sequence;
		int count = 1, result = 0;
		for (int index = 0; index < sequence.length(); index++) {
			if (sequence[index] == 'O') {
				result += count; count++;
			}
			else count = 1;
		}
		std::cout << result << '\n';
	}
}