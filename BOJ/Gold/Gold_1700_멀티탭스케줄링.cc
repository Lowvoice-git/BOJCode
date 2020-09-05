#include <iostream>
#include <vector>
#include <algorithm>

int N, K, result;
std::vector<int> Vector;
int Array[101];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int temp;
        std::cin >> temp;
        Vector.push_back(temp);
    }

    result = 0;

    for (int i = 0; i < Vector.size(); i++) {
        int element = Vector[i];

        bool check = false;
        for (int j = 1; j <= N; j++) {
            if (Array[j] == element) {
                check = true;
                break;
            }
        }

        if (!check) {
            bool empty = false;
            for (int j = 1; j <= N; j++) {
                if (Array[j] == 0) {
                    Array[j] = element;
                    empty = true;
                    break;
                }
            }
            if (!empty) {
                int index = 0,max = 0;
                bool reuse = true;
                for (int j = 1; j <= N; j++) {
                    int count = 1;
                    bool end = true;

                    for (int k = i; k < Vector.size(); k++, count++) {
                        if (Array[j] == Vector[k]) {
                            if (count > max) {
                                max = count;
                                index = j;
                            }
                            end = false;
                            break;
                        }
                    }
                    if (end) {
                        Array[j] = element;
                        result++;
                        reuse = false;
                        break;
                    }
                }
                if (reuse) {
                    Array[index] = element;
                    result++;
                }
            }
        }
    }

    std::cout << result;
}