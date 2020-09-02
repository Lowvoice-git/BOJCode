#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <climits>

typedef std::pair<int, int> PAIR;

char matrix[51][51];
int numbers[51][51];
int N, lower, upper;
bool visited[51][51];
PAIR P;
std::vector<PAIR> Vector;

PAIR direction[8] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

bool check(int Y, int X) {
	return (Y >= 0 && Y < N) && (X >= 0 && X < N);
}

bool possible() {
	int count = 0;

	for (int i = 0; i < Vector.size(); i++)
		if (visited[Vector[i].first][Vector[i].second])
			count++;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;

	return count == Vector.size();
}

void DFS(int Y, int X) {
	if (check(Y, X) && !visited[Y][X])
		if (numbers[Y][X] >= lower && numbers[Y][X] <= upper) {
			visited[Y][X] = true;

			for (int i = 0; i < 8; i++) {
				int ny = Y + direction[i].first;
				int nx = X + direction[i].second;

				DFS(ny, nx);
			}
		}
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];

			if (matrix[i][j] == 'P')
				P = { i,j };
			else if (matrix[i][j] == 'K')
				Vector.push_back({ i,j });
		}

	std::set<int> Set;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cin >> numbers[i][j];
			Set.insert(numbers[i][j]);
		}

	auto begin = Set.begin(), end = Set.begin();

	int result = INT_MAX;
	while (end != Set.end()) {
		while (begin != Set.end()) {
			lower = *begin;
			upper = *end;

			DFS(P.first, P.second);

			if (!possible())
				break;

			result = std::min(result, *end - *begin);
			begin++;
		}
		end++;
	}

	std::cout << result;
}