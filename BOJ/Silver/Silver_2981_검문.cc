#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> number, result;

int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; std::cin >> temp;
		number.push_back(temp);
	}
	std::sort(number.begin(), number.end());
	int gcd = number[1] - number[0];
	for (int i = 1; i < N - 1; i++)
		gcd = GCD(gcd, number[i + 1] - number[i]);
	for(int i=1;i*i<=gcd;i++)
		if (!(gcd % i)) {
			result.push_back(i);
			if (i != gcd / i)result.push_back(gcd / i);
		}
	std::sort(result.begin(), result.end());
	for (int e : result)
		if (e != 1) std::cout << e << ' ';

}