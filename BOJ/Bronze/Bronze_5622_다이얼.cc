#include <iostream>
#include <string>

int main() {
	std::string A;
	std::cin >> A;
	int sum = 0;

	for(int i=0;i<A.size();i++)
		switch (A[i]) {
		case 'A': case 'B': case 'C': sum += 2; break;
		case 'D': case 'E': case 'F': sum += 3; break;
		case 'G': case 'H': case 'I': sum += 4; break;
		case 'J': case 'K': case 'L': sum += 5; break;
		case 'M': case 'N': case 'O': sum += 6; break;
		case 'P': case 'Q': case 'R': case 'S':sum += 7; break;
		case 'T': case 'U': case 'V': sum += 8; break;
		default: sum += 9; break;
		}

	std::cout << sum + A.size();
}