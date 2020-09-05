#include <iostream>
#include <vector>
#include <map>
#include <string>

int set[200001];
int index[200001];

int Find(int E) {
	if (E == set[E]) return E;
	else return set[E] = Find(set[E]);
}

int Union(int A, int B) {
	A = Find(A); B = Find(B);
	if (A != B) {
		set[A] = B;
		index[B] += index[A];
		index[A] = 1;
	}
	return index[B];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		std::map<std::string, int> Map;
		int count = 1, N; std::cin >> N;
		for (int num = 1; num <= 2 * N; num++) {
			set[num] = num; index[num] = 1;
		}
		for (int num = 0; num < N; num++) {
			std::string A, B;
			std::cin >> A >> B;

			if (Map.count(A) == 0) Map[A] = count++;
			if (Map.count(B) == 0) Map[B] = count++;

			std::cout << Union(Map[A], Map[B]) << '\n';
		}
	}
}