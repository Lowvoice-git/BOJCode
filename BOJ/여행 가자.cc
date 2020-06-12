#include <iostream>
#include <vector>

std::vector<int> set;

int Find(int E) {
	if (E == set[E]) return E;
	else return set[E] = Find(set[E]);
}

void Union(int A, int B) {
	set[Find(A)] = Find(B);
}

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
	int N, M, A, B;
	std::cin >> N >> M;
	for (int num = 0; num <= N; num++)
		set.push_back(num);
	for(int Y=1;Y<=N;Y++)
		for (int X = 1; X <= N; X++) {
			bool check; std::cin >> check;
			if (check) Union(Y, X);
		}
	std::cin >> A;
	B = Find(A);
	for (int num = 1; num < M; num++) {
		std::cin >> A;
		if (B != Find(A)) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}