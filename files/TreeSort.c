#include <stdio.h>
#include <stdlib.h> 

typedef int element;		// 이진 탐색 트리 element의 자료형 정의
typedef struct treeNode {
	element key;				// 데이터 필드
	struct treeNode* left;  	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
} treeNode;

void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%5d", root->key);  //출력 형식 변경
		displayInorder(root->right);
	}
}
// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다!");
	return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
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
	else  printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {  // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // 왼쪽 서브 트리에서 후계자 찾기
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

// 트리 정렬 연산
void treeSort(int a[], int n) {
	treeNode* root = NULL;			// 공백 이진 탐색 트리 생성
	root = insertBSTNode(root, a[0]);	// a[0]을 공백 이진 탐색 트리의 루트로 삽입

	for (int i = 1; i < n; i++)		// a[1]~a[n-1]의 원소들을
		insertBSTNode(root, a[i]); // 삽입하면서 이진 탐색 트리 구성
	displayInorder(root);			 // 이진 탐색 트리를 중위 순회한 경로 출력
}

int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]); 	// list 배열의 원소 개수
	printf("\n정렬할 원소 : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n <<<<< 트리 정렬 수행 >>>>>> \n\n");
	treeSort(list, size);  // 트리 정렬 함수 호출

	getchar(); return 0;
}