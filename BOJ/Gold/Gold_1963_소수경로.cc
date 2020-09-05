#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#include <climits>

typedef std::pair<std::string, int> PAIR;

std::vector<bool> primeNumber(10001, true);
std::vector<int> visited;
std::queue<std::string> Queue;
int result = INT_MAX;

void Eratos() {
	for (int i = 2; i < 10001; i++) {
		int mult = 2;
		while (i * mult < 10001 && primeNumber[i] == true) {
			primeNumber[i * mult] = false; mult++;
		}
	}
}

bool check(int next) {
	return (next >= 1000 && primeNumber[next] && visited[next] == -1);
}

void BFS(std::string begin, std::string end) {
	Queue.push({ begin });

	while (!Queue.empty()) {
		std::string node = Queue.front();
		visited[std::stoi(begin)] = 0;
		Queue.pop();

		for (int i = 0; i < node.size(); i++) {
			std::string next = node;
			for (int j = 0; j < 10; j++) {
				next[i] = j + '0';

				if (check(std::stoi(next))) {
					visited[std::stoi(next)] = visited[std::stoi(node)] + 1;
					Queue.push(next);
				}
			}
		}
	}
}

int main() {
	Eratos();

	int T; std::cin >> T;
	while (T--) {
		visited = std::vector<int>(10001, -1);

		std::string begin, end;
		std::cin >> begin >> end;

		BFS(begin, end);

		if (visited[std::stoi(end)] == -1)
			std::cout << "Impossible\n";
		else std::cout << visited[std::stoi(end)] << '\n';
	}
}