#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> number;

int main() {
	std::string sequence;
	for(int num=0;num<3;num++){
		int temp; std::cin >> temp;
		number.push_back(temp);
	}
	std::cin >> sequence;
	std::sort(number.begin(),number.end());
	for(int num=0;num<3;num++) {
		std::cout << number[sequence[num] - 65] << ' ';
	}
}