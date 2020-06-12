#include <cstdio>
#include <cstdlib>
#include <algorithm>

int *vector;

int main() {
	int size;
	scanf("%d", &size);
	vector = (int*)calloc(size, sizeof(int));
	for (int _num = 0; _num < size; _num++) 
		scanf("%d", &vector[_num]);

	std::sort(vector, vector + size);

	for (int _num = 0; _num < size; _num++)
		printf("%d\n", vector[_num]);

	return 0;
}