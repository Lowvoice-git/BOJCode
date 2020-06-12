#include <iostream>
#include <algorithm>

int memo[1001], lengh, N;
int main() {
    std::cin >> N;
    for (int num = 1; num <= N; num++) {
        int temp;
        std::cin >> temp;
        auto check = std::lower_bound(memo + 1, memo + lengh + 1, temp);
        *check = temp;
        if (check == memo + lengh + 1)
            lengh++;
    }
    std::cout << lengh;
    return 0;
}