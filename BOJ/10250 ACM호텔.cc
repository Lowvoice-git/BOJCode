#include <iostream>

int main() {
	int T; std::cin >> T;
	while (T--) {
		int H, W, N, Y, X = 1;
		std::cin >> H >> W >> N;
		while (N > H) { N -= H; X++; }
		if (X < 10) std::cout << N << '0' << X << '\n';
		else std::cout << N << X << '\n';
	}
}