#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b;
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	cin >> a >> b;
	vector<int> v(b + 1, 0);
	v[1] = 1;
	for (int i = 2; i <= b; i++) {
		if (v[i] == 0)
			for (int k = i * 2; k <= b; k = k + i)
				v[k] = 1;
	}
	for (int i = a; i <= b; i++)
		if (v[i] == 0)
			cout << i << '\n';
}