#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int> Heap;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N; std::cin >> N;
	while (N--) {
		int temp; std::cin >> temp;
		if (temp) Heap.push(temp);
		else
			if (!Heap.empty()) {
				std::cout << Heap.top() << '\n';
				Heap.pop();
			}
			else 
				std::cout << 0 << '\n';
	}
}