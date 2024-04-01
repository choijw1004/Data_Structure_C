#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8

typedef int element;
// 연결 스택과 연결 큐의 노드
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

typedef struct LinkedStack {
	stackNode* top;
}Stack;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

int isFull(Stack* S) {
	return 0;
}
int isEmpty(Stack* S) {
	return S->top == NULL;
}

int QueueEmpty(Queue* Q) { // 큐 empty 확인
	return Q->front == NULL;
}

int	QueueFull(Queue* Q) { // 큐 full 확인
	return 0;
}
						
Stack* create() {
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}
// 공백큐 생성
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

element pop(Stack* S) {
	stackNode* temp; element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return -1;
	}
	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
		return e;
	}
}


void reverseStack(Stack* S, int k){
	Queue* que;
	createQueue(que);
	int i = 0;
	while (isEmpty(S) == 0 && i < k) {
		enqueue(que, pop(S));
		i++;
	}
	while (QueueEmpty(que) == 0) {
		push(S, dequeue(que));
	}
}
void enqueue(Queue* Q, element x) {
	queueNode* newNode =
		(queueNode*)malloc(sizeof(queueNode));
	newNode->data = x;
	newNode->link = NULL;
	if (isEmpty(Q))
		Q->front = newNode;
	else
		Q->rear->link = newNode;
	Q->rear = newNode;
}
element dequeue(Queue* Q) {
	queueNode* temp;
	element e;
	if (isEmpty(Q))
	{
		printf("[ERROR] Queue is EMPTY!!\n");
		return -1;
	}
	else  {
		temp = Q->front;
		e = temp->data;	
		Q->front = temp->link;
		free(temp);
		if (Q->front == NULL)
			Q->rear = NULL;
			return e;
	}
}



// 스택의 모든 요소 출력
void displayStack(Stack* S) {
	for (stackNode* p = S->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf(" ]\n");
}

int main(void) {
	Stack* S = create();
	push(S, 10); push(S, 20); push(S, 30); push(S, 40); push(S, 50); push(S, 60); push(S, 70);
	displayStack(S);
	
	
}