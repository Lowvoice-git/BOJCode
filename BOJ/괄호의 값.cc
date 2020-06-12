#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _STRUCT {
	char Sequence;
	int index;
}STRUCT;

class STACK {
public:
	int topIndex;
	STRUCT *stack;
	STACK() :topIndex(-1), stack(nullptr) {}
	void Init_STACK(size_t);
	void push(STRUCT);
	STRUCT pop();
};

int main() {
	STRUCT *sequence;
	STACK stack;
	char dumy_sequence[30];
	int check1 = 0;
	int check2 = 0;
	int result = 0;
	int mult = 1;

	scanf("%s", dumy_sequence);
	stack.Init_STACK(strlen(dumy_sequence));
	sequence = (STRUCT*)calloc(strlen(dumy_sequence), sizeof(STRUCT));
	for (int num = 0; num < strlen(dumy_sequence); num++) {
		sequence[num].Sequence = dumy_sequence[num];
		sequence[num].index = num;
	}

	for (int num = 0; num < strlen(dumy_sequence); num++) {
		STRUCT temp;
		switch (sequence[num].Sequence) {
		case '(':
			stack.push(sequence[num]);
			mult *= 2;
			check1++;
			break;
		case '[':
			stack.push(sequence[num]);
			mult *= 3;
			check2++;
			break;
		case ')':
			temp = stack.pop();
			if (temp.Sequence != '(') {
				printf("0");
				return 0;
			}
			if (temp.index + 1 == sequence[num].index)
				result += mult;
			mult /= 2;
			check1--;
			break;
		case ']':
			temp = stack.pop();
			if (temp.Sequence != '[') {
				printf("0");
				return 0;
			}
			if (temp.index + 1 == sequence[num].index)
				result += mult;
			mult /= 3;
			check2--;
			break;
		default:
			break;
		}
	}

	if (stack.topIndex < -1 || check1 != 0 || check2 != 0)
		printf("0");
	else printf("%d", result);
}

void STACK::Init_STACK(size_t index) {
	this->stack = (STRUCT*)calloc(index, sizeof(STRUCT));
}

void STACK::push(STRUCT data) {
	this->stack[++this->topIndex] = data;
}

STRUCT STACK::pop() {
	return this->stack[this->topIndex--];
}