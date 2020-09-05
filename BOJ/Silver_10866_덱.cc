#include <iostream>
#include <string>
#include <deque>

std::deque<int> Deque;

int main() {
	int N;
	std::cin.tie(NULL); std::ios::sync_with_stdio(false);
	std::cin >> N;
	while (N--) {
		std::string code; int data = 0;
		std::cin >> code;
		if (code == "push_back" || code == "push_front")
			std::cin >> data;
		if (code == "push_back") {
			Deque.push_back(data);
		}
		else if (code == "push_front") {
			Deque.push_front(data);
		}
		else if (code == "pop_back") {
			if (Deque.empty()) std::cout << -1 << '\n';
			else {
				std::cout << Deque.back() << '\n';
				Deque.pop_back();
			}
		}
		else if (code == "pop_front") {
			if (Deque.empty()) std::cout << -1 << '\n';
			else {
				std::cout << Deque.front() << '\n';
				Deque.pop_front();
			}
		}
		else if (code == "size") {
			std::cout << Deque.size() << '\n';
		}
		else if (code == "empty") {
			std::cout << Deque.empty() << '\n';
		}
		else if (code == "back") {
			if (Deque.empty()) std::cout << -1 << '\n';
			else std::cout << Deque.back() << '\n';
		}
		else if (code == "front") {
			if (Deque.empty()) std::cout << -1 << '\n';
			else std::cout << Deque.front() << '\n';
		}
	}
}