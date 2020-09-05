#include <iostream>

int main() {
    int H, M;
    std::cin >> H >> M;
    M = (H * 60) + M - 45; H = 0;
    if (M < 0) M += 1440;
    while (M >= 60) {
        H++; M -= 60;
    }
    std::cout << H << ' ' << M;
}