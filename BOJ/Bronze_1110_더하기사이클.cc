#include <iostream>
#include <string>

int count;
std::string number, compare;

void function() {
	int sum = (number[0] - '0') + (number[1] - '0');
	while (sum >= 10)
		sum -= 10;
	number[0] = number[1];
	number[1] = sum + '0';
	count++;
}

int main() {
	std::cin >> number;

	if (number.size() < 2)
		number = '0' + number;

	compare = number;
	function();
	
	while (compare != number)
		function();

	std::cout << count;
}