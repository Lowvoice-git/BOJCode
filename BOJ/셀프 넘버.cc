#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::vector<int> A;
	for (int i = 1; i < 10000; i++) {
		if (i < 10) A.push_back(i + i);
		else if (i < 100) A.push_back(i + i / 10 + i % 10);
		else if (i < 1000) A.push_back(i + i / 100 + i / 10 % 10 + i % 10);
		else A.push_back(i + i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10);
	}
	for (int i = 1; i <= 10000; i++) {
		bool check = false;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] == i) {
				check = true; break;
			}
		}
		if (!check) std::cout << i << std::endl;
	}
}