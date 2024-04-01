#include <stdio.h>
#include <stdlib.h> 

typedef int element;		// ���� Ž�� Ʈ�� element�� �ڷ��� ����
typedef struct treeNode {
	element key;				// ������ �ʵ�
	struct treeNode* left;  	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%5d", root->key);  //��� ���� ����
		displayInorder(root->right);
	}
}
// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)  p->left = insertBSTNode(p->left, x);
	else if (x > p->key)  p->right = insertBSTNode(p->right, x);
	else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}

// ��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {  // ������ ����� ��ġ Ž��
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// ������ ��尡 ���� ���
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // ���� ���� Ʈ������ �İ��� ã��
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)  succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

// Ʈ�� ���� ����
void treeSort(int a[], int n) {
	treeNode* root = NULL;			// ���� ���� Ž�� Ʈ�� ����
	root = insertBSTNode(root, a[0]);	// a[0]�� ���� ���� Ž�� Ʈ���� ��Ʈ�� ����

	for (int i = 1; i < n; i++)		// a[1]~a[n-1]�� ���ҵ���
		insertBSTNode(root, a[i]); // �����ϸ鼭 ���� Ž�� Ʈ�� ����
	displayInorder(root);			 // ���� Ž�� Ʈ���� ���� ��ȸ�� ��� ���
}

int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]); 	// list �迭�� ���� ����
	printf("\n������ ���� : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n <<<<< Ʈ�� ���� ���� >>>>>> \n\n");
	treeSort(list, size);  // Ʈ�� ���� �Լ� ȣ��

	getchar(); return 0;
}