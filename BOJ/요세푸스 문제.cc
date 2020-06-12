#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int data;
	struct _NODE *next;
	struct _NODE *preview;
}NODE;

class CLL {
public:
	int K, N;
	NODE *sequence;
	CLL() :K(0), N(0), sequence(nullptr) {}
	void Init_List(int);
	void Josephus(int, int, int*);
};

int main() {
	CLL list;
	int *result;
	scanf("%d %d", &list.K, &list.N);
	result = (int*)calloc(list.K, sizeof(int));
	list.Init_List(list.K);
	list.Josephus(list.K, list.N, result);
	for (int num = 0; num < list.K; num++) {
		if (list.K == 1)
			printf("<%d>", result[num]);
		else if (num == 0)
			printf("<%d,", result[num]);
		else if (num < list.K - 1)
			printf(" %d,", result[num]);
		else
			printf(" %d>", result[num]);
	}
}

void CLL::Init_List(int index) {
	this->sequence = (NODE*)calloc(1, sizeof(NODE));
	NODE *newNode = (NODE*)calloc(1, sizeof(NODE));
	this->sequence->next = newNode;
	newNode->data = 1;
	NODE *Current_Node = this->sequence->next;
	for (int num = 2; num <= index; num++) {
		NODE *newNode = (NODE*)calloc(1, sizeof(NODE));
		newNode->data = num;
		newNode->preview = Current_Node;
		Current_Node->next = newNode;
		Current_Node = Current_Node->next;
	}
	Current_Node->next = this->sequence->next;
	this->sequence->next->preview = Current_Node;
}

void CLL::Josephus(int K, int N, int *result) {
	int count = 1;
	int index = 0;
	NODE *pNode = this->sequence->next;
	NODE *pre_Node = this->sequence->next->preview;
	for (; this->sequence->next; count++) {
		if (count%N == 0 && count >= N) {
			result[index++] = pNode->data;
			pNode->next->preview = pre_Node;
			pre_Node->next = pNode->next;
			free(pNode);
			pNode = pre_Node;
			pre_Node = pNode->preview;
		}
		if (K*N != count) {
			pNode = pNode->next;
			pre_Node = pre_Node->next;
		}
		else
			this->sequence->next = nullptr;
	}
}