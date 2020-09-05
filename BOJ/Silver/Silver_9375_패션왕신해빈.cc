#include <iostream>
#include <map>

using namespace std;

int main() {

    int T, N, mult;
    std::string element, key;
    std::map <string, int> Map;
    std::pair<std::map<string, int>::iterator, bool > pMap;

    cin >> T;

    for (int i = 0; i < T; i++) {
        Map.clear();
        mult = 1;
        std::cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> element >> key;
            pMap = Map.insert(std::pair <std::string, int>(key, 1));
            if (!pMap.second) Map[key]++;
        }
        for (std::map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
            mult = mult * (it->second + 1);
        }
        std::cout << mult - 1 << endl;
    }

    return 0;
}