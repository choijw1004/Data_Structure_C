#include <stdio.h>
#include <stdlib.h>
#define TRUE
#define FALSE

//노드 구조체 정의
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

//리스트 구조체 정의
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
/*공백 리스트인 경우
* temp를 통해서 마지막 노드를 검색(L의 헤드 검색 원형이기 때문.)
새로운 노드의 링크값은 temp의 링크값으로 연결 (원형)
temp의 링크값은 새로운 노드로 연결
헤드값은 새로운 노드를 가리킴
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
//마지막 노드이기 때문에 temp는 새로운 노드를 가리키고 
// 새로운 노드는 L의 헤드를 가리킨다(첫번째 노드)
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