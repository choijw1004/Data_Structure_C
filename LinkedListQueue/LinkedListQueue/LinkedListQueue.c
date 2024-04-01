#include <stdio.h>
#include<stdlib.h>
#define ERROR -1

//��� ����ü ����
typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;
//front�� ù��° ��带 ����Ű�� �����ͺ����̰�
// rear�� ������ ��带 ����Ű�� ������ �����̴�
// ������ rear���� �Ͼ�� ������ front���� �Ͼ�� �����̴�.
//ť ����ü ����
typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

//������´� rear�� front�� �Ѵ� null
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
int isEmpty(Queue* Q) {
	return Q->front == NULL;
}

//���Ḯ��Ʈ�� ����ϱ⶧���� ������ ����.
int isFull(Queue* Q) {
	return 0;
}
//���Ḯ��Ʈ�� Ȱ���� ��ť�� �ܼ����Ḯ��Ʈ�� ������ ��忡 �����ϴ� ���� ����
//����ִٸ� front�� ���ο� ��带 ���ϰ�
//�׷��� �ʴٸ� q�� rear�� ����Ű���ִ� ����� ��ũ���� ���ο� ���
//rear�� ���ο� ��带 ����Ų��
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

//�ܼ����Ḯ��Ʈ���� �� ó�� ��带 �����ϴ� ���� ����.
//temp�� �˻������ʰ� ������ ��带 �����ϱ� ���� ���Ÿ�� �����ͺ���
//��尡 �ϳ�������� front�� null�� �Ǳ⶧���� rear �� null�� �ȴ�
//temp�� q�� front�� ����Ű���ִ� �ּҰ��� ����(temp�� ����� �� �ִ� ���·� ����)
//temp�� ������ �� temp front�� temp�� ���� ��ũ���� ���� �̾��ش�

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