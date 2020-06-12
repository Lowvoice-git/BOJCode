#include <cstdio>
#include <cstring>
#include <stack>

char vector[1000000];
char explosion_vector[36];

std::stack<std::pair<int, int>> stack;

void case1(int vector_lengh) {
	int result = 0;
	for (int _num = 0; _num < vector_lengh; _num++) {
		if (vector[_num] != explosion_vector[0]) {
			result = 1;
			printf("%c", vector[_num]);
		}
	}
	if (result)
		printf("\n");
	else
		printf("FRULA\n");
}

void case2(int vector_lengh, int explosion_vector_lengh) {
	int result = 0;
	for (int _num = 0; _num < vector_lengh; _num++) {
		if (vector[_num] == explosion_vector[0])
			stack.push(std::make_pair(_num, 0));
		else {
			if (stack.empty())
				continue;
			if (vector[_num] == explosion_vector[stack.top().second + 1]) {
				stack.push(std::make_pair(_num, stack.top().second + 1));
				if (stack.top().second + 1 == explosion_vector_lengh) {
					for (int __num = 0; __num < explosion_vector_lengh; __num++) {
						vector[stack.top().first] = '.';
						stack.pop();
					}
				}
			}
			else
				while (!stack.empty())
					stack.pop();
		}
	}

	for (int _num = 0; _num < vector_lengh; _num++) {
		if (vector[_num] != '.') {
			result = 1;
			printf("%c", vector[_num]);
		}
	}

	if (result)
		printf("\n");
	else
		printf("FRULA\n");
}

int main() {
	scanf("%s\n%s", vector, explosion_vector);

	if (strlen(explosion_vector) == 1)	case1(strlen(vector));
	else								case2(strlen(vector), strlen(explosion_vector));

	return 0;
}