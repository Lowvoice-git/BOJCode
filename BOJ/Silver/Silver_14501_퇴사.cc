#include <iostream>
#include <algorithm>

int N, T[16], P[16], DP[16], result;

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        std::cin >> T[i] >> P[i];

    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j < i; j++) {
            DP[i] = std::max(DP[i], DP[j]);

            if (j + T[j] == i)
                DP[i] = std::max(DP[i], DP[j] + P[j]);
        }
        result = std::max(result, DP[i]);
    }
    std::cout << result;
}