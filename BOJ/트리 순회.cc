#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char data;
	struct _Node *leftChild;
	struct _Node *rightChild;
} Node;

Node *root;
Node *searched_node;

void search_node(char data, Node *tree = root) {
	if (!tree) return;
	else if (tree->data == data) searched_node = tree;
	else {
		search_node(data, tree->leftChild);
		search_node(data, tree->rightChild);
	}
	return;
}



void insert_node(char parentData, char leftChildData, char rightChildData) {
	if (!root) {
		root			= (Node*)calloc(1, sizeof(Node));
		root->leftChild	= (Node*)calloc(1, sizeof(Node));
		root->rightChild= (Node*)calloc(1, sizeof(Node));

		root->data = parentData;
		if (leftChildData != '.'&&rightChildData != '.') {
			root->leftChild->data	= leftChildData;
			root->rightChild->data	= rightChildData;
		}
		else if (leftChildData != '.') {
			root->leftChild->data = leftChildData;
			free(root->rightChild); 
			root->rightChild = nullptr;
		}
		else if (rightChildData != '.') {
			root->rightChild->data = rightChildData;
			free(root->leftChild); 
			root->leftChild = nullptr;
		}
		else {
			free(root->leftChild); 
			root->leftChild = nullptr;
			free(root->rightChild); 
			root->rightChild = nullptr;
		}
	}
	else {
		Node *left_newNode	= (Node*)calloc(1, sizeof(Node));
		Node *right_newNode	= (Node*)calloc(1, sizeof(Node));
		left_newNode->data	= leftChildData;
		right_newNode->data	= rightChildData;
		search_node(parentData);
		if (leftChildData != '.'&&rightChildData != '.') {
			searched_node->leftChild	= left_newNode;
			searched_node->rightChild	= right_newNode;
		}
		else if (leftChildData != '.') {
			searched_node->leftChild	= left_newNode;
			free(right_newNode);
		}
		else if (rightChildData != '.') {
			searched_node->rightChild	= right_newNode;
			free(left_newNode);
		}
		else {
			free(left_newNode);
			free(right_newNode);
		}
	}
}

void preorder_print(Node *tree = root) {
	if (!tree) return;
	printf("%c", tree->data);
	preorder_print(tree->leftChild);
	preorder_print(tree->rightChild);
}

void inorder_print(Node *tree = root) {
	if (!tree) return;
	inorder_print(tree->leftChild);
	printf("%c", tree->data);
	inorder_print(tree->rightChild);
}

void postorder_print(Node *tree = root) {
	if (!tree) return;
	postorder_print(tree->leftChild);
	postorder_print(tree->rightChild);
	printf("%c", tree->data);
}

int main() {
	int node_count; char input[26][6];
	char parentData[26]; char leftChildData[26]; char rightChildData[26];
	scanf("%d", &node_count); while (getchar() != '\n');

	for (int _num = 0; _num < node_count; _num++) {
		gets(input[_num]);
		parentData[_num]		= input[_num][0];
		leftChildData[_num]	= input[_num][2];
		rightChildData[_num]	= input[_num][4];
	}

	for (int _num = 0; _num < node_count; _num++)
		insert_node(parentData[_num], leftChildData[_num], rightChildData[_num]);

	preorder_print();   printf("\n");
	inorder_print();    printf("\n");
	postorder_print();

	return 0;
}