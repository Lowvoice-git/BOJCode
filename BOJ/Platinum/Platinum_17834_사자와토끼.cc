#include <iostream>
#include <vector>

typedef long long int LL;

LL Array[1010101];
std::vector<LL> Vector[1010101];
LL Visited[1010101];

LL countA, countB, check;

void DFS(LL node) {
    for (auto i : Vector[node]) {
        if (Visited[i] == 0) {
            Visited[i] = 3 - Visited[node];

            if (Visited[i] == 1)
                countA++;
            else
                countB++;

            DFS(i);
        }
        else if (Visited[i] == Visited[node]) {
            check = 1;
            return;
        }
    }
}

int main() {
    LL i, j, k, l, M, N;
    std::cin >> N >> M;

    while (M--) {
        LL A, B;
        std::cin >> A >> B;

        Vector[A].push_back(B);
        Vector[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        if (Visited[i]) continue;

        countA++;
        Visited[i] = 1;

        DFS(i);
    }

    if (check) std::cout << 0;
    else std::cout << 2 * countA * countB;
}
