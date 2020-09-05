#include <iostream>
#include <deque>
#include <string>
#include <cstring>

std::deque<int> Deque;

int main() {
	int N; scanf("%d", &N);
	while (N--) {
		char code[100005], sequence[400005]; int element_number;
		scanf("%s %d %s", code, &element_number, sequence);
		char *temp = strtok(sequence, "[,]");
		while (temp) {
			Deque.push_back(std::stoi(temp));
			temp = strtok(nullptr, "[,]");
		}
		bool reverse_check = false, isEmpty = false;
		for (int num = 0; code[num] != '\0'; num++) {
			if (code[num] == 'R') {
				if (reverse_check) reverse_check = false;
				else reverse_check = true;
			}
			else {
				if (Deque.empty()) { isEmpty = true; break; }
				else {
					switch (reverse_check) {
					case true: { Deque.pop_back(); break; }
					case false: { Deque.pop_front(); break; }
					}
				}
			}
		}
		if (isEmpty) {
			printf("error\n"); Deque.clear();
		}
		else if (reverse_check) {
			printf("[");
			if (Deque.size()) {
				while (Deque.size() - 1 != 0) {
					printf("%d,", Deque.back()); Deque.pop_back();
				}
				printf("%d", Deque.back()); Deque.pop_back();
			}
			printf("]\n");
		}
		else {
			printf("[");
			if (Deque.size()) {
				while (Deque.size() - 1 != 0) {
					printf("%d,", Deque.front()); Deque.pop_front();
				}
				printf("%d", Deque.front()); Deque.pop_front();
			}
			printf("]\n");
		}
	}
}