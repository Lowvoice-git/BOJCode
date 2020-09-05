#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
long long temp = 0;
std::vector<long long> block;

long long binary_search(int begin, int end) {

	long long sum = 0;
	long long middle = (begin + end) / 2;

	if (temp == middle) return temp;
	else temp = middle;

	if (middle == 0)
		return 0;

	for (int num = 0; num < N; num++)
		if ((block[num] - middle) > 0)
			sum += (block[num] - middle);

	if (sum > M)
		return binary_search(middle, end);
	else if (sum < M)
		return binary_search(begin, middle);
	else
		return middle;
}

int main() {
	std::cin >> N >> M;
	for (int num = 0; num < N; num++) {
		int temp; std::cin >> temp;
		block.push_back(temp);
	}
	std::sort(block.begin(), block.end());

	std::cout << binary_search(0, block.back());
}