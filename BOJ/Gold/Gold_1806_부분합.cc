#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

int subSetSum = 0;
std::vector<int> Vector;

int main() {
	int N, sum = 0; int count = INT_MAX;
	std::cin >> N >> sum;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		Vector.push_back(temp);
	}

	auto begin = Vector.begin();
	auto end = Vector.begin();

	while (begin != Vector.end() || end != Vector.end()) {
		if (subSetSum < sum && begin != Vector.end()) {
			subSetSum += (*begin);
			begin++;
		}
		else if (subSetSum >= sum || begin == Vector.end()) {
			if (subSetSum >= sum) {
				int length = begin - end;
				count = std::min(count, length);
			}

			subSetSum -= (*end);
			end++;
		}
	}
	if (count == INT_MAX)
		std::cout << 0;
	else
		std::cout << count;
}