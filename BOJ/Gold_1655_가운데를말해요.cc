#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, temp;
    std::cin >> N;

    while (N--)
    {
        std::cin >> temp;

        if (maxHeap.empty()) maxHeap.push(temp);
        else if (maxHeap.size() == minHeap.size())
            maxHeap.push(temp);
        else minHeap.push(temp);

        if (!maxHeap.empty() && !minHeap.empty() && !(maxHeap.top() <= minHeap.top()))
        {
            int a = maxHeap.top();
            int b = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            maxHeap.push(b);
            minHeap.push(a);
        }

        std::cout << maxHeap.top() << '\n';
    }
}