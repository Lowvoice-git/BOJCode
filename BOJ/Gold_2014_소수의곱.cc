#include <iostream>
#include <queue>
#include <vector>
#include <functional>

typedef long long LL;

std::priority_queue<LL, std::vector<LL>, std::greater<LL>> Queue;
std::vector<int> Vector;

int main() {
	int N, K;
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
		Queue.push(Vector.back());
	}

	LL head = 0;
	for (int i = 0; i < K; i++) {
		head = Queue.top();
		Queue.pop();

		for (int j = 0; j < N; j++) {
			LL value = head * Vector[j];
			Queue.push(value);

			if (head % Vector[j] == 0)
				break;
		}
	}

	std::cout << head;
}