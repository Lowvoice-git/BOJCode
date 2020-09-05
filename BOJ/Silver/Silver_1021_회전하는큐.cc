#include <iostream>
#include <deque>
#include <queue>
#include <iterator>

std::deque<int> Deque;
std::queue<int> Queue;

int main(void) {
	int size, pop_number, result = 0;
	scanf("%d %d", &size, &pop_number);
	for (int num = 0; num < pop_number; num++) {
		int temp; scanf("%d", &temp);
		Queue.push(temp);
	}
	for (int num = 1; num <= size; num++)
		Deque.push_back(num);
	while (!Queue.empty()) {
		int front_count = 0, back_count = 1;
		std::deque<int>::iterator front_iter = Deque.begin();
		std::deque<int>::reverse_iterator back_iter = Deque.rbegin();
		for (auto num = front_iter; num != Deque.end(); num++) {
			if ((*num) == Queue.front()) break;
			else front_count++;
		}
		for (auto num = back_iter; num != Deque.rend(); num++) {
			if ((*num) == Queue.front()) break;
			else back_count++;
		}
		if (front_count <= back_count) {
			for (int num = 0; num < front_count; num++) {
				Deque.push_back(Deque.front());
				Deque.pop_front();
			}
			result += front_count;
			Deque.pop_front();
			Queue.pop();
		}
		else {
			for (int num = 0; num < back_count; num++) {
				Deque.push_front(Deque.back());
				Deque.pop_back();
			}
			result += back_count;
			Deque.pop_front();
			Queue.pop();
		}
	}
	printf("%d", result);
}