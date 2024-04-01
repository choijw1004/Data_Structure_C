#include <stdio.h>
void radixSort(int a[], int n);
#include <stdio.h>

#define RADIX 10	// ������ �ڷ���� Ű���� 10�����̹Ƿ� RADIX�� 10���� ����
#define DIGIT 2		// ������ �ڷ���� Ű���� �� �ڸ��̹Ƿ� DIGIT�� 2�� ����

typedef int element;     // ���� ť ����(element)�� �ڷ����� char�� ����
typedef struct QNode {    // ���� ť�� ��带 ����ü�� ����
	element data;
	struct QNode* link;
} QNode;

typedef struct {		// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
	QNode* front, * rear;
} LQueueType;

#include <stdio.h>
#include <stdlib.h>

// ���� ���� ť�� �����ϴ� ����
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		//printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// ���� ���� ť�� ���� ������ ���
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// ���� ���� ť�� ���� ���°� �ƴ� ���
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

// ���� ť���� ���Ҹ� �˻��ϴ� ����
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;
		return item;
	}
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3d", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}
// �迭 a�� �ִ� n�� ���ҿ� ���ؼ� ��� ������ �����ϴ� ����
void radixSort(int a[], int n) {
	int i, bucket, d, factor = 1;

	// ������ �ڷ��� ���, �� RADIX�� ���� 10���� ��Ŷ�� ť�� ����
	LQueueType* Q[RADIX];  // ��Ŷ ť�� ��� �����͸� ������ �迭�� ����
	for (bucket = 0; bucket < RADIX; bucket++)
		Q[bucket] = createLinkedQueue();

	// Ű���� �ڸ�����ŭ, �� �� �� ��� ������ �ݺ� ����
	for (d = 0; d < DIGIT; d++) {
		for (i = 0; i < n; i++)
			enLQueue(Q[(a[i] / factor) % RADIX], a[i]);
		for (bucket = 0, i = 0; bucket < RADIX; bucket++)
			while (!isLQEmpty(Q[bucket]))  a[i++] = deLQueue(Q[bucket]);
		printf("\n\n %d �ܰ� : ", d + 1);
		for (i = 0; i < n; i++)  printf(" %3d", a[i]);

		factor = factor * RADIX;
	}
}
int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]); 	// list �迭�� ���� ����
	printf("\n������ ���� : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n <<<<< ��� ���� ���� >>>>>>");
	radixSort(list, size);  // ��� ���� �Լ� ȣ��

	getchar();  return 0;
}