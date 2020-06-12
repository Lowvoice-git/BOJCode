#include <iostream>
#include <string>
#include <map>
using namespace std;
std::map<string, int> AVLTree;
std::map<string, int>::reverse_iterator iter;

int main(void) {
	ios_base::sync_with_stdio(false);
	int number = 0;
	string name;
	string info;

	cin >> number;
	for (int num = 0; num < number; num++) {
		cin >> name >> info;
		if (info == "enter") {
			AVLTree.insert(make_pair(name, num));
		}
		else {
			AVLTree.erase(name);
		}
	}

	for (iter = AVLTree.rbegin(); iter != AVLTree.rend(); iter++)
		cout << iter->first << '\n';

	return 0;
}