#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <functional>

std::deque<int> Deque;
std::deque<int> minusDeque;

int main() {
	int N; std::cin >> N;
	int zeroCount = 0, sum = 0, oneCount = 0;

	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		if (temp == 0) zeroCount++;
		else if (temp == 1) oneCount++;
		else if (temp < 0) minusDeque.push_back(temp);
		else Deque.push_back(temp);
	}

	std::sort(minusDeque.begin(), minusDeque.end());

	while (minusDeque.size() >= 2) {
			sum += minusDeque[0] * minusDeque[1];
			minusDeque.pop_front();
			minusDeque.pop_front();
	}

	for (int i = 0; i < zeroCount; i++)
		if (minusDeque.empty()) continue;
		else minusDeque.pop_front();

	std::sort(Deque.begin(), Deque.end(), std::greater<int>());
	
	while (!Deque.empty()) {
		if (Deque.size() < 2) {
			sum += Deque.front();
			Deque.pop_front();
		}
		else {
			sum += Deque[0] * Deque[1];
			Deque.pop_front();
			Deque.pop_front();
		}
	}

	for (int i = 0; i < minusDeque.size(); i++)
		sum += minusDeque[i];

	std::cout << sum + oneCount;
}