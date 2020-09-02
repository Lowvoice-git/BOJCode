#include <iostream>

int main() {
	while (true) {
		int A, B, C; bool check = false;
		std::cin >> A >> B >> C;
		if (A + B + C == 0) break;
		A *= A; B *= B; C *= C;
		if (C == B + A) check = true;
		else if (A == B + C) check = true;
		else if (B == A + C) check = true;

		if (check) std::cout << "right\n";
		else std::cout << "wrong\n";
	}
}