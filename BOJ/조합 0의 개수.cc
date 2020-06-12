#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::pair<long long, long long> function(long long N) {
	long long number_2 = 0, number_5 = 0;
	for (long long i = 2; i <= N; i *= 2)
		number_2 += N / i;
	for (long long i = 5; i <= N; i *= 5)
		number_5 += N / i;
	return std::make_pair(number_2, number_5);
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::pair<long long, long long> result[3];
	result[0] = function(N);
	result[1] = function(M);
	result[2] = function(N - M);
	std::cout << std::min(result[0].first - result[1].first - result[2].first, result[0].second - result[1].second - result[2].second);
}