#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 100000000

bool compare(int left, int right) {
	return left < right;
}

int main() {

	int N, temp, Array[8001], sum = 0, mode_temp = -1, mode;
	std::vector<int> vec, mode_vec;
	for (int num = 0; num < 8001; num++)
		Array[num] = 0;
	scanf("%d", &N);
	for (int num = 0; num < N; num++) {
		scanf("%d", &temp);
		vec.push_back(temp);
		sum += temp;
		temp = (temp <= 0) ? abs(temp) : temp + 4000;
		Array[temp]++;
		if (Array[temp] > mode_temp) {
			mode_temp = Array[temp];
			mode = temp;
		}
	}
	std::sort(vec.begin(), vec.end(), compare);
	for (int num = 0; num < 8001; num++) {
		if (Array[num] == mode_temp) {
			mode = num;
			mode = (mode <= 4000) ? -mode : mode - 4000;
			mode_vec.push_back(mode);
		}
	}
	std::sort(mode_vec.begin(), mode_vec.end(), compare);
	mode = (mode_vec.size() >= 2) ? mode_vec[1] : mode_vec[0];
	printf("%.0f\n", (double)sum / (double)N);
	printf("%d\n", vec[N / 2]);
	printf("%d\n", mode);
	printf("%d\n", vec[vec.size() - 1] - vec[0]);
}