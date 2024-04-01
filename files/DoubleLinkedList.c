#include <stdio.h>
#include <stdlib.h>
#define TRUE
#define FALSE

//노드 구조체 정의
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* llink, * rlink;
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
/* 공백리스트인 경우
더블연결리스트이기때문에 왼쪽노드는 NULL
새로운 노드의 rlink는 원래 헤드가 바라보던 노드를 가리킴
새로운 노드의 오른쪽 노드의 llinke값은 새로운 노드를 바라보게함
헤드값은 새로운 노드를 바라보게한다
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
/* 중간node로 삽입하는 경우 pre가 주어짐
* 공백 리스트인 경우
* 맨처음노드로 삽입하는 경우 rlink는 L의 헤드가 가리키고 값
* 새로운 노드의 오른쪽값은 pre가 가리키고있던 rlinke의 값
* pre의 rlink는 새로운 노드를 가리킨다
* 새로운 노드의 llink 값은 pre를 가리킨다
* 다음노드가 있는경우 다음 노드의 llink는 새로운 노드를 바라본다.
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

//4번의 과정 거침
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
/* 공백리스트인경우 false
* 삭제할 노드가 없는경우 false
* 첫번째 노드가 삭제되는 경우
* 삭제되는 노드가 마지막 노드인 경우
* 삭제되는 노드의 오른쪽 노드의 왼쪽값이 p가 기존에 가리키던 llink의 값이 된다.
*/
int delete(linkedList* L, listNode* p) {
	// Fill your code
	if (L->head == NULL)  //공백리스트
		return FALSE;
	if (p == NULL)  //삭제할 노드가 없는 경우
		return FALSE;
	if (p->llink == NULL) //첫번쨰 노드인 경우
				L->head = p->rlink;
	else 
		p->llink->rlink = p->rlink; 
	//그냥 p를 찾아주는 것
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
// listnode pre p 매개변수 사용방법, 책과의 차이, 