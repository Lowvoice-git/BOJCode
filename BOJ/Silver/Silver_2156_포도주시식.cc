#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {

    int N; std::cin >> N;
    std::vector<int> Array(N + 1), memo(N + 1);

    for (int num = 1; num <= N; num++)
        std::cin >> Array[num];

    for (int num = 1; num < 3 && num <= N; num++)
        if (num == 1) memo[num] = Array[num];
        else memo[num] = Array[num] + Array[num - 1];

    for (int num = 3; num <= N; num++) {
        memo[num] = std::max(Array[num] + memo[num - 2], memo[num - 1]);
        memo[num] = std::max(memo[num], Array[num] + Array[num - 1] + memo[num - 3]);
    }

    std::cout << memo[N];
}