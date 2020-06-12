#include <iostream>
#include <string>
#include <deque>

std::deque<int> Deque;

int main() {
	int N, K; std::string number;
	std::cin >> N >> K >> number;
	for (int num = 0; num < number.length(); num++) {
		while (K && !Deque.empty() && Deque.back() < number[num] - '0') {
			Deque.pop_back(); K--;
		}
		Deque.push_back(number[num] - '0');
	}
	for (int num = 0; num < Deque.size() - K; num++)
		std::cout << Deque[num];
}