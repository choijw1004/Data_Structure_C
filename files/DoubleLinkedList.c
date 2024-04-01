#include <stdio.h>
#include <stdlib.h>
#define TRUE
#define FALSE

//��� ����ü ����
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* llink, * rlink;
}listNode;

//����Ʈ ����ü ����
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}
/* ���鸮��Ʈ�� ���
�����Ḯ��Ʈ�̱⶧���� ���ʳ��� NULL
���ο� ����� rlink�� ���� ��尡 �ٶ󺸴� ��带 ����Ŵ
���ο� ����� ������ ����� llinke���� ���ο� ��带 �ٶ󺸰���
��尪�� ���ο� ��带 �ٶ󺸰��Ѵ�
*/
void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
		// Fill your code
		if (L->head == NULL) {
			newNode->rlink = NULL;
			newNode->llink = NULL;
				L->head = newNode;
		}
		else {
			newNode->llink = NULL;
				newNode->rlink = L->head;
			newNode->rlink->llink = newNode;
			L->head = newNode;
		}
	L->length++;
}
/* �߰�node�� �����ϴ� ��� pre�� �־���
* ���� ����Ʈ�� ���
* ��ó������ �����ϴ� ��� rlink�� L�� ��尡 ����Ű�� ��
* ���ο� ����� �����ʰ��� pre�� ����Ű���ִ� rlinke�� ��
* pre�� rlink�� ���ο� ��带 ����Ų��
* ���ο� ����� llink ���� pre�� ����Ų��
* ������尡 �ִ°�� ���� ����� llink�� ���ο� ��带 �ٶ󺻴�.
*/
void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL)
		insertFirst(L, x);
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
	L->length++;
}
/*

void inserLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->rlink = NULL;
	while (temp->rlink != NULL) 
		temp = temp->rlink;
	/////////////////////////////////////////
	
	newNode->llink = temp;
	temp->rlink = newNode;
	L->length++;
}*/

//4���� ���� ��ħ
void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
		// Fill your code
	newNode->rlink = NULL;
		if (L->head == NULL) {
			newNode->llink = NULL;
				L->head = newNode;
		}
		else {
			temp = L->head;
			while (temp->rlink!= NULL)
				temp = temp->rlink;
			newNode->llink = temp;
			temp->rlink = newNode;
		}
	L->length++;
}
/* ���鸮��Ʈ�ΰ�� false
* ������ ��尡 ���°�� false
* ù��° ��尡 �����Ǵ� ���
* �����Ǵ� ��尡 ������ ����� ���
* �����Ǵ� ����� ������ ����� ���ʰ��� p�� ������ ����Ű�� llink�� ���� �ȴ�.
*/
int delete(linkedList* L, listNode* p) {
	// Fill your code
	if (L->head == NULL)  //���鸮��Ʈ
		return FALSE;
	if (p == NULL)  //������ ��尡 ���� ���
		return FALSE;
	if (p->llink == NULL) //ù���� ����� ���
				L->head = p->rlink;
	else 
		p->llink->rlink = p->rlink; 
	//�׳� p�� ã���ִ� ��
	if (p->rlink != NULL)
		p->rlink->llink = p->llink;
	free(p);
	L->length--;
	return TRUE;
}
listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}
void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}
int main(void) {
	linkedList* list = initList();
	listNode* temp;
	insertFirst(list, 10);
	temp = search(list, 10);
	insert(list, temp, 30);
	insertLast(list, 123);
	displayList(list);
	
	return 0;
}
// listnode pre p �Ű����� �����, å���� ����, 