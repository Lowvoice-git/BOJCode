#include <iostream>
#include <vector>

int main() {
	int sum = 0, count = 0;
	int N; std::cin >> N;

	std::vector<bool> primeNumbers(N + 1, true);

	primeNumbers[0] = primeNumbers[1] = false;

	for (int i = 2; i <= N; i++) {
		int mult = 2;
		while (i * mult <= N && primeNumbers[i] == true) {
			primeNumbers[i * mult] = false; mult++;
		}
	}

	int begin = 0, end = 0;

	while (begin != N || end != N) {
		if (sum < N && begin != N) {

			sum += primeNumbers[begin] ? begin : 0;
			begin++;
		}
		else if (sum >= N || begin == N)
		{
			if (sum == N && primeNumbers[end]) count++;

			sum -= primeNumbers[end] ? end : 0;
			end++;
		}
	}

	std::cout << count + primeNumbers[N];
}