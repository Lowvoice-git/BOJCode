#include <iostream>
#include <queue>

std::queue<int> Queue;

int main(void) {
	int N, result = 0;
	scanf("%d", &N);
	for (int num = 1; num <= N; num++)
		Queue.push(num);
	while (!Queue.empty()) {
		if (Queue.size() == 1) {
			result = Queue.front();
			break;
		}
		Queue.pop();
		Queue.push(Queue.front());
		Queue.pop();
	}
	printf("%d", result);
}