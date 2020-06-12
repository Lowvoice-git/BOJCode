#include <iostream>
#include <string>

int main() {
    int A, mul[3], sum = 0, ten = 1;
    std::string B;
    std::cin >> A >> B;
    for (int i = 2; i >= 0; i--, ten*=10) {
        mul[i] = A * (B[i] - '0');
        sum += mul[i] * ten;
        std::cout << mul[i] << '\n';
    }
    std::cout << sum;
}