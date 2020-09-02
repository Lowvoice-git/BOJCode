#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long ULL;

std::string F[101];
ULL f[101];

std::vector<int> InitArray(std::string S) {
	int temp = 0;
	std::vector<int> Array(S.length());
	for (int i = 1; i < S.length(); i++) {
		while (temp > 0 && S[i] != S[temp])
			temp = Array[temp - 1];
		Array[i] = temp = (S[i] == S[temp]) ? temp + 1 : 0;
	}
	return Array;
}

std::vector<int> KMP(std::string S, std::string P, int index) {
	int i = 0, j = 0;
	std::vector<int> result, Array = InitArray(P);
	while (i + j < S.length()) {
		if (j > index) break;
		if (S[i + j] == P[i]) {
			if (i == P.length() - 1)
				result.push_back(j);
			else {
				i++;
				continue;
			}
		}
		if (i > 0) {
			j = j + i - Array[i - 1];
			i = Array[i - 1];
		}
		else {
			j = j + 1;
			i = 0;
		}
	}
	return result;
}

ULL finder(int N, std::string P) {
	if (P == "0") {
		if (N < 2) return (N == 0) ? 1 : 0;
		return f[N - 2];
	}
	if (P == "1") {
		if (N < 2) return (N == 0) ? 0 : 1;
		return f[N - 1];
	}

	int index = 3;
	while (f[index - 3] <= P.length()) index++;
	if (index > N) index = N;

	ULL A = 0, B = 0, binary[2]; binary[0] = binary[1] = 0;
	std::vector<int> FP = KMP(F[index], P, (int)f[index - 1]);
	for (int E : FP) {
		if (E < f[index - 2])
			if ((ULL)(E + P.length() - 1) < f[index - 2]) B++;
			else binary[0]++;
		else if (E < f[index - 1])
			if ((ULL)(E + P.length() - 1) < f[index - 1]) A++;
			else binary[1]++;
	}

	for (int i = 0; i <= N - index + 1; i++) {
		ULL temp = B;
		B = B + A + binary[i % 2];
		A = temp;
	}

	return B;
}

int main() {
	F[0] = "0"; F[1] = "1";
	f[0] = f[1] = 1;

	for (int i = 1; i < 3 || F[i - 3].length() < 100000; i++)
		F[i + 1] = F[i] + F[i - 1];

	for (int i = 1; i < 100; i++)
		f[i + 1] = f[i] + f[i - 1];

	int N; std::string P;
	for (int i = 1; std::cin >> N >> P; i++)
		std::cout << "Case " << i << ": " << finder(N, P) << '\n';
}