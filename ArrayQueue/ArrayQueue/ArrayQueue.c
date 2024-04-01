#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define ERROR -1

// �迭 ����ü ����
typedef int element;
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
}Queue;
//���� ������ ������ �Ͼ�� rear�� front�� ���� ���������� �̵��Ѵ�
// �� �κп� ���ڸ��� ������ rear�� MAX_SIZE -1 ���¶�� ��ȭ���·� �ν�
// ���� ť ���
// rear = (rear + 1) mod MAX_SIZE
// front = (front + 1) mod MAX_SIZE
// �׻� ���ڸ��� ��������Ѵ�.
// ť ����ü ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
// ť�� ���� �������� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�
int isFull(Queue * Q) {
		return (Q->rear + 1) % MAX_SIZE == Q->front;
}
// rear�� front�� ���� ��(0)�� �ٶ󺸰������� ��������̴�.
int isEmpty(Queue* Q) {
		return Q->front == Q->rear;
}
//�迭�̱⶧���� ������ ���� �������� �ʾƵ��� 
//rear�� �̵��ñ��ȴ�
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
	printf("ó������: %d\n", Q->queue[Q->rear]);
	printf("����������: %d", Q->queue[Q->front]);
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

