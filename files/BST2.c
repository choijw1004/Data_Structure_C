#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define EMPTY

typedef struct treeNode {
	int x;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* create_Node() {
	treeNode* p = (treeNode*)malloc(sizeof(treeNode));
	p->x = NULL;
	p->left = NULL;
	p ->right = NULL;
	return  p;
}

treeNode* insert(treeNode* root, int x)
{
	if (root == NULL)
	{
		root = (treeNode*)malloc(sizeof(treeNode));
		root->right = root->left = NULL;
		root->x = x;
		return root;
	}
	else
	{
		if (x < root->x)
			root->left = insert(root->left, x);
		else
			root->right = insert(root->right, x);
	}
	return root;
}

void printTree(treeNode* p) {
	if (p != NULL) {
		printTree(p->left);
		printf("%d\n", p->x);
		printTree(p->right);
	}
}


int main(void) {
	treeNode* root = create_Node();
	insert(root, 10);
	insert(root, 20);
	insert(root, 30);
	insert(root, 40);
	insert(root, 50);
	printTree(root);
}