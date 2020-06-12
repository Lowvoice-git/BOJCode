#include <iostream>
#include <utility>

int main() {
	std::pair<int, int> point[3], result;
	for (int i = 0; i < 3; i++)
		std::cin >> point[i].first >> point[i].second;

	if (point[0].first == point[1].first)
		result.first = point[2].first;
	else if (point[0].first == point[2].first)
		result.first = point[1].first;
	else result.first = point[0].first;

	if (point[0].second == point[1].second)
		result.second = point[2].second;
	else if (point[0].second == point[2].second)
		result.second = point[1].second;
	else result.second = point[0].second;

	std::cout << result.first << ' ' << result.second;
}