#include <iostream>
#include <map>

long long N, P, Q;
std::map<long long, long long> Map;

long long function(long long N) {
	if (Map.count(N)) {
		return Map[N];
	}
	else return Map[N] = function(N / P) + function(N / Q);
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> N >> P >> Q;
	Map[0] = 1;
	std::cout << function(N) << "\n";
}