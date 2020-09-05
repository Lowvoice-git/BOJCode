#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> lucky_number;

int main() {
	int n, unlucky_number, count = 0;
	std::cin >> n;
	lucky_number.push_back(0);
	for (int num = 0; num < n; num++) {
		int temp; std::cin >> temp;
		lucky_number.push_back(temp);
	}
	std::cin >> unlucky_number;
	std::sort(lucky_number.begin(), lucky_number.end());
	for (int num = 0; num < n; num++)
		if (lucky_number[num] < unlucky_number && lucky_number[num + 1] > unlucky_number)
			for (int end = unlucky_number; end < lucky_number[num + 1]; end++)
				for (int begin = lucky_number[num] + 1; begin < end; begin++)
					if (begin <= unlucky_number && end >= unlucky_number) count++;
	std::cout << count;
}