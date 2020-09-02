#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> PAIR;

std::vector<PAIR> Vector;

int getDistance(PAIR A, PAIR B) {
	return std::pow(A.first - B.first, 2) + std::pow(A.second - B.second, 2);
}

int divideAndConque(int begin, int end) {
	int result = INT_MAX;
	int pointCount = end - begin + 1;
	if (pointCount <= 3) {
		for (int i = begin; i < end; i++)
			for (int j = i + 1; j <= end; j++)
				result = std::min(result, getDistance(Vector[i], Vector[j]));
	}
	else {
		int middle = (begin + end) / 2;
		int left = divideAndConque(begin, middle - 1);
		int right = divideAndConque(middle + 1, end);
		result = std::min(left, right);

		std::vector<PAIR> temp;
		temp.push_back({ Vector[middle].second,Vector[middle].first });

		for (int i = middle - 1; i >= begin; i--) {
			if (std::pow(Vector[middle].first - Vector[i].first, 2) >= result)
				break;
			temp.push_back({ Vector[i].second,Vector[i].first });
		}

		for (int i = middle + 1; i <= end; i++) {
			if (std::pow(Vector[middle].first - Vector[i].first, 2) >= result)
				break;
			temp.push_back({ Vector[i].second,Vector[i].first });
		}

		std::sort(temp.begin(), temp.end());

		for (int i = 0; i < temp.size() - 1; i++)
			for (int j = i + 1; j < temp.size(); j++) {
				if (std::pow(temp[i].first - temp[j].first, 2) >= result)
					break;
				result = std::min(result, getDistance(temp[i], temp[j]));
			}
	}
	return result;
}

int main() {
	int N; std::cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B; std::cin >> A >> B;
		Vector.push_back({ A,B });
	}
	std::sort(Vector.begin(), Vector.end());
	std::cout << divideAndConque(0, N - 1);
}