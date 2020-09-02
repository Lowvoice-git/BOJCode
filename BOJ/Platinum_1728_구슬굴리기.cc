#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> PAIR;

int N;
std::vector<int> Vector[501];

bool check(int s, int t) {
	for (int i = 2; i <= N; i++) {
		int v = (s + t * i);
		for (int j = 0; j < N; j++) {
			if (Vector[i][j] == v)
				break;
			if (j == N - 1)
				return false;
		}
	}
	return true;
}

int main() {
	std::cin >> N;
	for(int i=0;i<=N;i++)
		for (int j = 0; j < N; j++) {
			int temp; std::cin >> temp;
			Vector[i].push_back(temp);
		}

	std::vector<PAIR> result;
	for (int i = 0; i < N; i++) {
		int s = Vector[0][i];
		for (int j = 0; j < N; j++) {
			int t = Vector[1][j] - s;

			if (check(s, t)) {
				result.push_back({ s,t });
				break;
			}
		}
	}

	std::sort(result.begin(), result.end());
	for (auto i : result)
		std::cout << i.first << ' ' << i.second << '\n';
}