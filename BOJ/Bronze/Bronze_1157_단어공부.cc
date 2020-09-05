#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

std::pair<int,char> memo[26];

bool compare(const std::pair<int, char> &A, const std::pair<int, char> &B) {
	return A.first < B.first;
}

int main() {
	std::string word;
	std::cin >> word;

	std::transform(word.begin(), word.end(), word.begin(), tolower);
	for (int i = 0; i < 26; i++)
		memo[i].second = 'A' + i;
	for (int i = 0; i < word.size(); i++)
		memo[word[i] - 'a'].first++;
	std::sort(memo, memo + 26, compare);
	if (memo[25].first == memo[24].first)
		std::cout << '?';
	else std::cout << memo[25].second;
}