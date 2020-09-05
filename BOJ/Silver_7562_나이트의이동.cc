#include <iostream>
#include <vector>
#include <utility>
#include <queue>

std::vector<std::pair<int, int>> direction = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1} };
int main() {
	int N; std::cin >> N;
	while (N--) {
		int lengh;
		std::pair<int, int> begin, end;
		std::cin >> lengh >> begin.second >> begin.first >> end.second >> end.first;
		std::vector<std::vector<int>> visit(lengh, std::vector<int>(lengh, 0));
		std::queue<std::pair<std::pair<int, int>, int>> Queue;
		Queue.push(std::make_pair(std::make_pair(begin.first, begin.second), 0));
		visit[begin.first][begin.second]++;

		while (!Queue.empty()) {
			int y = Queue.front().first.first;
			int x = Queue.front().first.second;
			int count = Queue.front().second;
			Queue.pop();

			if (y == end.first && x == end.second) {
				std::cout << count << '\n'; break;
			}

			for (int num = 0; num < 8; num++) {
				int ny = y + direction[num].first;
				int nx = x + direction[num].second;

				if (ny < 0 || ny >= lengh || nx < 0 || nx >= lengh) continue;
				if (visit[ny][nx]) continue;

				visit[ny][nx]++;
				Queue.push(std::make_pair(std::make_pair(ny, nx), count + 1));
			}
		}
	}
}