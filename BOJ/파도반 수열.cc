#include <iostream>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		std::vector<long long> Vector;
		int index; scanf("%d", &index);
		for (int num = 0; num < 3; num++) Vector.push_back(1);
		for (int num = 0; num < 2; num++) Vector.push_back(2);
		for (int i = 5, num = 0; i < index; i++, num++) {
			Vector.push_back(Vector[num] + Vector[num + 4]);
		}
		printf("%lld\n", Vector[index - 1]);
	}
}