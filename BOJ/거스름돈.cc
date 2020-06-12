#include <iostream>

int main() {
	int cash, result = 0;
	int Array[6] = { 500,100,50,10,5,1 };
	std::cin >> cash;
	cash = 1000 - cash;
	for (int num = 0; num < 6; num++)
		if (cash >= Array[num]) {
			result += cash / Array[num];
			cash %= Array[num];
		}
	std::cout << result;
}