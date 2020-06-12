#include <stdio.h>
#include <stdlib.h>

class STACK {
private:
public:
	int topIndex;
	int *stack;
	void Init_Stack(int);
	void push(int);
	int	pop();
};

class FUNCTION {
private:
	int	*Array;
	int	*Sequence;
	char*result;
	int number;
	int temp_number;
	int result_index;
public:
	FUNCTION() :Array(nullptr), Sequence(nullptr), result(nullptr), number(0), temp_number(0), result_index(0) {}
	void Init_Arrays(int);
	int makeSquence(STACK&);
	void print_result();
};

int main() {
	int index = 0;
	STACK stack;
	FUNCTION function;

	scanf("%d", &index);

	stack.Init_Stack(index);
	function.Init_Arrays(index);

	for (int num = 0; num < index; num++) {
		if (function.makeSquence(stack)) {
			printf("NO");
			return 0;
		}
	}

	function.print_result();
}
void STACK::Init_Stack(int index) {
	this->topIndex = -1;
	this->stack = (int*)calloc(index, sizeof(int));
}

void STACK::push(int data) {
	this->topIndex++;
	this->stack[this->topIndex] = data;
}

int STACK::pop() {
	this->topIndex--;
	return this->stack[this->topIndex + 1];
}

void FUNCTION::Init_Arrays(int index) {
	this->Array		= (int*)calloc(index, sizeof(int));
	this->Sequence	= (int*)calloc(index, sizeof(int));
	this->result		= (char*)calloc(index * 2, sizeof(char));

	for (int num = 0; num < index; num++) {
		scanf("%d", &this->Array[num]);
		this->Sequence[num] = num + 1;
	}
}

int FUNCTION::makeSquence(STACK &Stack) {
	if (Stack.stack[Stack.topIndex] > this->Array[this->number])
		return 1;
	if (Stack.stack[Stack.topIndex] == this->Array[this->number]) {
		if (this->temp_number < this->Array[this->number])
			this->temp_number = Stack.pop();
		else Stack.pop();
		this->number++;
		this->result[this->result_index++] = '-';
	}
	else {
		for (int num = this->temp_number; num < this->Array[this->number]; num++) {
			Stack.push(this->Sequence[num]);
			this->result[this->result_index++] = '+';
		}
		makeSquence(Stack);
	}
	return 0;
}

void FUNCTION::print_result() {
	for (int num = 0; num < this->result_index; num++)
		printf("%c\n", this->result[num]);
}