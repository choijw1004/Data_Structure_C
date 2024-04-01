#include<stdio.h>
#include<stdlib.h>

//노드 구조체 정의
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

//스택 구조체 정의 head가 top으로 변경된 것 뿐
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create() {
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

int isEmpty(Stack* S) {
	return S->top == NULL;
}

int isFull(Stack* S) {
	return 0;
}
//가장 먼저 생성된 노드는 마지막 노드가 되고 최근에 생성된 노드는 첫번째 노드가 된다
//따라서 먼저 생성된 노드의 link값은 null
// 단순연결리스트의 첫번째 노드에 삽입하는 연산과 동일하다.
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

//단순 연결리스트의 맨 처음 노드를 삭제하는 경우와 같음 
//top은 기존의 기존의 temp가 가리키던 값(temp.link)의 값을 가리킨다
element pop(Stack* S) {
	stackNode* temp; element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
		//return ERROR;
	}
	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
		return e;
	}
}

element peek(Stack* S) {
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
		//return ERROR;
	}
	else
		return S->top->data;
}

void print(Stack* S){
	
	printf("최상단의 값은%d", S->top);
	}

int main(void) {
	Stack* S = create();
	push(S, 10);
	pop(S);
	print(S);

}