#include <stdio.h>
#include <stdlib.h>
#define TRUE
#define FALSE

//��� ����ü ����
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
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
/*���� ����Ʈ�� ���
* temp�� ���ؼ� ������ ��带 �˻�(L�� ��� �˻� �����̱� ����.)
���ο� ����� ��ũ���� temp�� ��ũ������ ���� (����)
temp�� ��ũ���� ���ο� ���� ����
��尪�� ���ο� ��带 ����Ŵ
*/
void insertFirstCir(linkedList* L, element x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = L->head;
		while (temp->link != L->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;
		L->head = newNode;
	}
	L->length++;
}
void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++;
}
//������ ����̱� ������ temp�� ���ο� ��带 ����Ű�� 
// ���ο� ���� L�� ��带 ����Ų��(ù��° ���)
void inserLastNodeCircu(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	temp = L->head;
	while (temp->link != L->head)
		newNode->link = L->head;
	temp->link = newNode;
	newNode->link = L->head;
	L->length++;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->link;
	}
	return temp;
}
void displayList(linkedList* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p->link != L->head) {
		printf(" % d", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}
/// <summary>
/// ///////////////////
/// </summary>
/// <param name=""></param>
/// <returns></returns>

int main(void) {
	linkedList* list = initList();
	
	
}