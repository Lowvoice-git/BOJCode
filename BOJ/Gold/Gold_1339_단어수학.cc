#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::string> Vector;
int visited[26];

int main() {
	int N, count = 9, result = 0; std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string temp; std::cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			visited[temp[j] - 'A'] += std::pow(10, temp.length() - j - 1);
	}
	std::sort(visited, visited + 26, std::greater<int>());
	for (int i = 0; i < 26; i++) {
		if (visited[i] != 0)
			result += visited[i] * count--;
		else break;
	}
	std::cout << result;
}