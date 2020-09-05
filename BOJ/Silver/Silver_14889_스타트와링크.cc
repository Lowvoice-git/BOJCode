#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

int N, matrix[21][21], result = INT_MAX;

std::vector<int> A, B;
std::pair<int, int> sum, start, link;

void DFS(int level) {
    if (level == N + 1) {
        if (A.size() == N / 2 && B.size() == N / 2) {
            sum = { 0,0 };

            for (int i = 0; i < N / 2; i++) {
                for (int j = i + 1; j < N / 2; j++) {
                    if (i == j) continue;

                    start.first = A[i];
                    start.second = A[j];

                    sum.first += matrix[start.first][start.second] + matrix[start.second][start.first];

                    link.first = B[i];
                    link.second = B[j];

                    sum.second += matrix[link.first][link.second] + matrix[link.second][link.first];
                }
            }
            result = std::min(result, std::abs(sum.first - sum.second));

        }
        return;
    }

    A.push_back(level);
    DFS(level + 1);
    A.pop_back();

    B.push_back(level);
    DFS(level + 1);
    B.pop_back();
}

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> matrix[i][j];

    DFS(1);

    std::cout << result;
}