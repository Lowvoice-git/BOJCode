#include <iostream>
#include <string>

int main() {
	int N, count = 0; std::cin >> N;
	for (int i = 0; i < N; i++) {
		bool check = true;
		int alphabet[26] = {0,};
		std::string A;
		std::cin >> A;
		for (int j = 0, n = 1; j < A.size(); j++, n++) {
			if (alphabet[A[j] - 'a'] == 0)
				alphabet[A[j] - 'a'] = n;
			else if (n - alphabet[A[j] - 'a'] == 1)
				alphabet[A[j] - 'a'] = n;
			else check = false;
		}
		if (check) count++;
	}
	std::cout << count;
}