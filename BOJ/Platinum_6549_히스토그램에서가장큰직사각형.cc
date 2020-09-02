#include <stdio.h>
#include <vector>

typedef long long LL;

void Init_segmentTree(std::vector<int> &Array, std::vector<int> &segmentTree, int Node, int start, int end) {
	if (start == end)
		segmentTree[Node] = start;
	else {
		int middle = (start + end) / 2;
		Init_segmentTree(Array, segmentTree, Node * 2, start, middle);
		Init_segmentTree(Array, segmentTree, Node * 2 + 1, middle + 1, end);
		if (Array[segmentTree[Node * 2]] <= Array[segmentTree[Node * 2 + 1]])
			segmentTree[Node] = segmentTree[Node * 2];
		else segmentTree[Node] = segmentTree[Node * 2 + 1];
	}
}

int Min_Height(std::vector<int> &Array, std::vector<int> &segmentTree, int Node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return -1;
	if (left <= start&&right >= end)
		return segmentTree[Node];

	int middle = (start + end) / 2;
	int result1 = Min_Height(Array, segmentTree, Node * 2, start, middle, left, right);
	int result2 = Min_Height(Array, segmentTree, Node * 2 + 1, middle + 1, end, left, right);

	if (result1 == -1) return result2;
	else if (result2 == -1) return result1;
	else {
		if (Array[result1] <= Array[result2]) return result1;
		else return result2;
	}
}

LL getMax(std::vector<int> &Array, std::vector<int> &segmentTree, int start, int end) {
	int size = Array.size();
	int basement = Min_Height(Array, segmentTree, 1, 0, size - 1, start, end);

	LL area = (LL)(end - start + 1) * (LL)Array[basement];

	if (start <= basement - 1) {
		LL temp = getMax(Array, segmentTree, start, basement - 1);
		if (area < temp) area = temp;
	}
	if (basement + 1 <= end) {
		LL temp = getMax(Array, segmentTree, basement + 1, end);
		if (area < temp) area = temp;
	}
	return area;
}

int main(void) {
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;
		std::vector<int> Array(N);
        std::vector<int> segmentTree(N * 4);
		for (int num = 0; num < N; num++)
			scanf("%d", &Array[num]);
		Init_segmentTree(Array, segmentTree, 1, 0, N - 1);
		printf("%lld\n", getMax(Array, segmentTree, 0, N - 1));
	}
	return 0;
}