#include <iostream>

int set[1000001];

int Find(int E) {
	if (E == set[E]) return E;
	else return set[E] = Find(set[E]);
}

void Union(int A, int B) {
	set[Find(B)] = Find(A);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	for (int num = 0; num <= N; num++)
		set[num] = num;
	while (M--) {
		int code, A, B;
		std::cin >> code >> A >> B;
		if (code)
			if (Find(A) == Find(B)) std::cout << "YES\n";
			else std::cout << "NO\n";
		else Union(A, B);
	}
}