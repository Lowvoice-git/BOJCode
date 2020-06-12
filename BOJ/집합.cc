#include <iostream>
#include <set>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::set<int> Set;

	int T, N; 
	std::cin >> T;
	while (T--) {
		std::string code;
		std::cin >> code;
		switch (code[0]) {
		case 'a':
			if(code == "add") {
				std::cin >> N;
				Set.insert(N);
				
			}
			else Set.insert({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
			break;
		case 'e':
			Set.clear();
			break;
		case 'c':
			std::cin >> N;
			if (Set.end() != Set.find(N))
				std::cout << 1 << '\n';
			else std::cout << 0 << '\n';
			break;
		case 't':
			std::cin >> N;
			if (Set.end() != Set.find(N))
				Set.erase(N);
			else Set.insert(N);
			break;
		case 'r':
			std::cin >> N;
			Set.erase(N);
			break;
		default:
			break;
		}
	}
}