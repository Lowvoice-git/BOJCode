#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Node {
	Node *left, *right;
	int num, height;
	char name[23];

	Node(int n, char* String) {
		left = right = 0;
		num = n;
		height = 0;
		strcpy(name, String);
	};

};



struct Tree {
	Node* root;

	Tree() { root = 0; }

	Node* insert(Node* Current_Node, Node* pNode) {
		if (Current_Node == 0) return pNode;
		if (strcmp(Current_Node->name, pNode->name) > 0) {
			Current_Node->left = insert(Current_Node->left, pNode);
		}
		else Current_Node->right = insert(Current_Node->right, pNode);

		int LeftHeight = -1, RightHeight = -1;

		if (Current_Node->left)  LeftHeight = Current_Node->left->height;
		if (Current_Node->right) RightHeight = Current_Node->right->height;

		Current_Node->height = 1 + max(LeftHeight, RightHeight);

		int balance = LeftHeight - RightHeight;

		if (balance > 1 && strcmp(Current_Node->left->name, pNode->name) > 0) {
			Current_Node = rightRotate(Current_Node);
		}
		else if (balance > 1 && strcmp(Current_Node->left->name, pNode->name) < 0) {
			Current_Node->left = leftRotate(Current_Node->left);
			Current_Node = rightRotate(Current_Node);
		}
		else if (balance < -1 && strcmp(Current_Node->right->name, pNode->name) < 0) {
			Current_Node = leftRotate(Current_Node);
		}
		else if (balance < -1 && strcmp(Current_Node->right->name, pNode->name) > 0) {
			Current_Node->right = rightRotate(Current_Node->right);
			Current_Node = leftRotate(Current_Node);
		}
		return Current_Node;
	}

	Node* rightRotate(Node* Current_Node) {
		Node* ret = Current_Node->left;
		Current_Node->left = ret->right;
		ret->right = Current_Node;

		int LeftHeight = -1, RightHeight = -1;

		if (Current_Node->left)  LeftHeight = Current_Node->left->height;
		if (Current_Node->right) RightHeight = Current_Node->right->height;

		Current_Node->height = max(LeftHeight, RightHeight) + 1;

		LeftHeight = -1, RightHeight = -1;

		if (ret->left)  LeftHeight = ret->left->height;
		if (ret->right) RightHeight = ret->right->height;

		ret->height = max(LeftHeight, RightHeight) + 1;

		return ret;
	}

	Node* leftRotate(Node* Current_Node) {
		Node* ret = Current_Node->right;

		Current_Node->right = ret->left;
		ret->left = Current_Node;

		int LeftHeight = -1, RightHeight = -1;

		if (Current_Node->left)  LeftHeight = Current_Node->left->height;
		if (Current_Node->right) RightHeight = Current_Node->right->height;

		Current_Node->height = max(LeftHeight, RightHeight) + 1;

		LeftHeight = -1, RightHeight = -1;

		if (ret->left)  LeftHeight = ret->left->height;
		if (ret->right) RightHeight = ret->right->height;

		ret->height = max(LeftHeight, RightHeight) + 1;

		return ret;
	}

	int Search(char* String) {
		Node* now = root;

		while (now) {
			int value = strcmp(now->name, String);

			if (value == 0) return now->num;
			else if (value > 0) now = now->left;
			else now = now->right;
		}
		return -1;
	}
};

int main() {
	int count, question_count;
	char name[(int)1e5 + 1][23];

	scanf("%d %d", &count, &question_count);

	Tree* tree = new Tree();

	for (int num = 1; num <= count; num++) {
		scanf("%s", name[num]);

		Node* newNode = new Node(num, name[num]);
		tree->root = tree->insert(tree->root, newNode);
	}
	while (question_count--) {
		char _name[23];

		scanf("%s", _name);

		if ('0' <= _name[0] && _name[0] <= '9') {
			int num = 0;
			for (int i = 0; _name[i]; i++) {
				num *= 10;
				num += (_name[i] - '0');
			}
			printf("%s\n", name[num]);
		}
		else printf("%d\n", tree->Search(_name));
	}
}