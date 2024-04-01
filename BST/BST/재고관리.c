#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_CODE_LENGTH 7 // 관리번호 길이 정의
#define EMPTY

// 재고관리를 위한 구조체 정의
// 관리번호, 재고수량

typedef int itemStock;

typedef struct {
	char itemCode[MAX_CODE_LENGTH];
	itemStock stock;
} item;
// 재고관리를 위한 이진트리 노드 구조체 정의

typedef struct treeNode {
	item key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* deleteNode(treeNode* root, item key);

treeNode* new_node(item key)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->key = key;
	root->left = root->right = NULL;
	return root;
}

int compare(item e1, item e2)
{
	return strcmp(e1.itemCode, e2.itemCode);
}

treeNode* inOrder(treeNode* root, item key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (root == NULL) {
		printf("상품코드 %s의 재고는 %d개 입니다", key.itemCode, key.stock);
		return new_node(key);
	}
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (compare(key, root->key) == 0)
	{
		printf("\n");
		printf("존재하는 상품코드 입니다\n");
		root->key.stock += key.stock;
		printf("상품코드 %s의 재고는 %d개 입니다", root->key.itemCode, root->key.stock);
		//return root;
	}
	if (compare(key, root->key) < 0)
		root->left = inOrder(root->left, key);
	if (compare(key, root->key) > 0)
		root->right = inOrder(root->right, key);
	// 루트 포인터를 반환한다.
	
	return root;

}
treeNode* outOrder(treeNode* root, item key) {
	treeNode* p = root;
	treeNode* parent = NULL;
	int a = 0;
	int b = 0;
	while (p != NULL) {
		if (compare(p->key, key) == 0)
			break;
		parent = p;
		if (compare(p->key, key) < 0)
			p = p->right;
		else
			p = p->left;
	}
	if (p == NULL)
	{
		printf("존재하지 않는 상품번호 입니다.");
		return;
	}
	printf("존재하는 상품코드 입니다\n");
	printf("상품코드 %s의 재고는 %d개 입니다\n", p->key.itemCode, p->key.stock);

	while (a == 0) {
		printf("\n[출고] 출고 수량을 선택하세요: ");
		scanf("%d", &a);
		if (a == 0)
			printf("잘못된 입력입니다");
	}
	b = p->key.stock;
	p->key.stock -= a;
	if (p->key.stock <= 0)
	{
		printf("재고가 모두 소진되어 %d개만 출고합니다\n", b);
		return deleteNode(root, key);

	}
	else
	{
		printf("상품코드 %s의 재고는 %d개 입니다\n", p->key.itemCode, p->key.stock);
		return root;
	}
}

void printMenu() {
	printf("\n");
	printf("\n*====SELECT MENU=====*\n");
	printf("    1: 재고관리\n");
	printf("    2: 입고\n");
	printf("    3: 출고\n");
	printf("    4: 검색\n");
	printf("    5: 종료\n");
	printf("\n*=====================*\n");
	printf("\n");

}

void display(treeNode* root) {
	if (root != NULL) {
		display(root->left);
		printf("\n관리번호:  %s, 재고:  %d", root->key.itemCode, root->key.stock);
		display(root->right);
	}
}

void search(treeNode* root, item key) {
	if (root == NULL)
		printf("존재하지 않는 상품코드입니다");
	else {
		if (compare(key, root->key) == 0)
		{
			printf("\n");
			printf("존재하는 상품코드 입니다\n");
			printf("상품코드 %s의 재고는 %d개 입니다", root->key.itemCode, root->key.stock);

		}
		else if (compare(key, root->key) < 0)
			search(root->left, key);
		else
			search(root->right, key);
	}
}
treeNode* deleteNode(treeNode* root, item key) {
	treeNode* parent, *p, *succ, *succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;

	while (p != NULL) {
		if (compare(p->key, key) == 0)
			break;
		parent = p;
		if (compare(p->key, key) < 0)
			p = p->right;
		else
			p = p->left;
	}

	//첫번째 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) 
				parent->left = NULL;
			else parent->right = NULL;
		}
		else return NULL;
		
	}

	//삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent ->left = child;
			else parent ->right = child;
		}

		else {
			root = child;
			return child;
		}
	}

	//삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
	  succ_parent = p;
	  succ = p->left;

	  //왼쪽 서브 트리에서 후계자 찾기
	  while (succ->right != NULL) {
		succ_parent = succ;
		succ = succ->right;
	  }

	  if (succ_parent ->left == succ) succ_parent ->left = succ->left;
	  else succ_parent->right = succ->left;

	  p->key= succ->key;
	  p = succ;
	}

	free(p);
	return root;
	
}



int main(void) {
	int menu;
	item key;
	treeNode* p;
	treeNode* root = NULL;

	do {
		printMenu();
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("[전체 재고 출력]\n");
			printf("\n");
			display(root);
			break;
		case 2:
			printf("[입고] 관리번호를 입력하세요: ");
			scanf_s("%s", key.itemCode, MAX_CODE_LENGTH);
			printf("[입고] 입고 수량을 선택하세요: ");
			scanf("%d", &key.stock);
			if (key.stock <= 0)
				printf("잘못된 입력입니다");
			else {
				root = inOrder(root, key);
			}
			break;
		case 3:
			printf("[출고] 관리번호를 입력하세요: ");
			scanf_s("%s", key.itemCode, MAX_CODE_LENGTH);
			root = outOrder(root, key);
			break;
		case 4:
			printf("[재고 수량 검색] 관리번호를 입력하세요: ");
			scanf_s("%s", key.itemCode, MAX_CODE_LENGTH);
			search(root, key);
			break;

		}
	} while (menu != 5);
	return 0;
}


