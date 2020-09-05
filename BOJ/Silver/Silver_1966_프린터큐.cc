#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> Queue;
std::vector<int> compare;

int main(void) {
	int N;
	scanf("%d", &N);
	while (N--) {
		int page_number, page_index;
		scanf("%d %d", &page_number, &page_index);
		for (int num = 0; num < page_number; num++) {
			int page_priority;
			scanf("%d", &page_priority);
			Queue.push_back({ page_priority,num });
			compare.push_back(page_priority);
		}
		std::sort(compare.begin(), compare.end(), std::greater<int>());
		int index = 0;
		bool Switch = true;
		while (Switch) {
			bool check = false;
			for (int num = index; num < Queue.size(); num++) {
				if ((Queue[index].first < Queue[num].first)) {
					Queue.push_back(Queue[index]);
					Queue.erase(Queue.begin() + index);
					check = false;
					break;
				}
				else check = true;
			}
			if (check) index++;
			for (int num = 0; num < compare.size(); num++) {
				if (Queue[num].first == compare[num]) Switch = false;
				else { Switch = true; break;  }
			}
		}
		for (int num = 0; num < Queue.size(); num++)
			if (page_index == Queue[num].second)
				printf("%d\n", num + 1);
		Queue.clear(); compare.clear();
	}
}