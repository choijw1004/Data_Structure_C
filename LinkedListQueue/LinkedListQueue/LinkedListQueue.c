#include <stdio.h>
#include<stdlib.h>
#define ERROR -1

//노드 구조체 정의
typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;
//front는 첫번째 노드를 가리키는 포인터변수이고
// rear은 마지막 노드를 가리키는 포인터 변수이다
// 삽입은 rear에서 일어나고 삭제는 front에서 일어나기 때문이다.
//큐 구조체 정의
typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

//공백상태는 rear와 front가 둘다 null
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
int isEmpty(Queue* Q) {
	return Q->front == NULL;
}

//연결리스트를 사용하기때문에 제한이 없다.
int isFull(Queue* Q) {
	return 0;
}
//연결리스트를 활용한 인큐는 단순연결리스트의 마지막 노드에 삽입하는 경우와 동일
//비어있다면 front는 새로운 노드를 향하고
//그렇지 않다면 q의 rear가 가리키고있는 노드의 링크값은 새로운 노드
//rear은 새로운 노드를 가리킨다
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

//단순연결리스트에서 맨 처음 노드를 삭제하는 경우와 같다.
//temp는 검색하지않고 기존의 노드를 삭제하기 위한 노드타입 포인터변수
//노드가 하나였을경우 front는 null이 되기때문에 rear 도 null이 된다
//temp는 q의 front가 가리키고있는 주소값을 갖고(temp를 써먹을 수 있는 형태로 만듦)
//temp를 날리기 전 temp front가 temp의 다음 링크값을 가져 이어준다

element dequeue(Queue* Q) {
	queueNode* temp;
	element e;
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	else {
		temp = Q->front;
		e = temp->data;
		Q->front = temp->link;
		free(temp);
	if (Q->front == NULL)
		Q->rear = NULL;
	return e;
}
}
void print_list(Queue * Q) {
	printf("%d",Q->rear->data);
	
	

}
int main(void) {
	Queue* Q = create();
	enqueue(Q, 10);
	enqueue(Q, 20);
	enqueue(Q, 30);
	enqueue(Q, 40);
	print_list(Q);
	

}