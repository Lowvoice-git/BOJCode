#include <cstdio>
#include <map>
#include <algorithm>

static long long result[300000];

int main() {
	int node_count;
	long long int count = 0;

    scanf("%d", &node_count);
    
	std::map<int, long long> mapContainer;
	std::map<int, long long>::iterator lower;
	std::map<int, long long>::iterator higher;

	mapContainer.insert(std::pair<int, long long>(0, -1));
	mapContainer.insert(std::pair<int, long long>(300001, -1));
	
	for (int _num = 0; _num < node_count; _num++) {
		int data; scanf("%d", &data);
		long long int depth = 0;
		lower	= (--mapContainer.lower_bound(data));
		higher	= (mapContainer.upper_bound(data));
		depth	= std::max(lower->second, higher->second) + 1;

		mapContainer.insert(std::pair<int, long long>(data, depth));

		count += depth;

		result[_num] = count;
	}

	for (int _num = 0; _num < node_count; _num++)
		printf("%lld\n", result[_num]);

	return 0;
}