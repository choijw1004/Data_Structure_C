#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define ERROR -1

// 배열 구조체 정의
typedef int element;
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
}Queue;
//삽입 삭제가 여러번 일어나면 rear와 front는 점점 오른쪽으로 이동한다
// 앞 부분에 빈자리가 있지만 rear가 MAX_SIZE -1 상태라면 포화상태로 인식
// 원형 큐 사용
// rear = (rear + 1) mod MAX_SIZE
// front = (front + 1) mod MAX_SIZE
// 항상 한자리는 비워놔야한다.
// 큐 구조체 정의
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
// 큐가 가득 차있으면 1을 반환하고 그렇지 않으면 0을 반환한다
int isFull(Queue * Q) {
		return (Q->rear + 1) % MAX_SIZE == Q->front;
}
// rear와 front가 같은 값(0)을 바라보고있으면 공백상태이다.
int isEmpty(Queue* Q) {
		return Q->front == Q->rear;
}
//배열이기때문에 기존의 값을 삭제하지 않아도됨 
//rear를 이동시기면된다
void enqueue(Queue* Q, element x) {
	if (isFull(Q)) {
		printf("[ERROR] Queue is FULL!!\n");
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MAX_SIZE;
		Q->queue[Q->rear] = x;
	}
}

element dequeue(Queue* Q) {
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return ERROR;
	}
	else {
		Q->front = (Q->front + 1) % MAX_SIZE;
		return Q->queue[Q->front];
	}
}

element peek(Queue* Q) {
	if (isEmpty(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");
		return;
	}
	else {
		return Q->queue[(Q->front + 1) % MAX_SIZE];
	}
}
void printQ(Queue* Q) {
	printf("처음값은: %d\n", Q->queue[Q->rear]);
	printf("마지막값은: %d", Q->queue[Q->front]);
}
int main(void) {
	Queue* Q = create();
	enqueue(Q, 10);
	enqueue(Q, 10);
	enqueue(Q, 10);
	enqueue(Q, 10);
	enqueue(Q, 20);
	printQ(Q);


}

