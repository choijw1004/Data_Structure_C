#include <stdio.h>
void radixSort(int a[], int n);
#include <stdio.h>

#define RADIX 10	// 정렬할 자료들의 키값이 10진수이므로 RADIX를 10으로 정의
#define DIGIT 2		// 정렬할 자료들의 키값이 두 자리이므로 DIGIT를 2로 정의

typedef int element;     // 연결 큐 원소(element)의 자료형을 char로 정의
typedef struct QNode {    // 연결 큐의 노드를 구조체로 정의
	element data;
	struct QNode* link;
} QNode;

typedef struct {		// 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
	QNode* front, * rear;
} LQueueType;

#include <stdio.h>
#include <stdlib.h>

// 공백 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		//printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// 현재 연결 큐가 공백 상태인 경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// 현재 연결 큐가 공백 상태가 아닌 경우
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
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

// 연결 큐에서 원소를 검색하는 연산
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;
		return item;
	}
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3d", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}
// 배열 a에 있는 n개 원소에 대해서 기수 정렬을 수행하는 연산
void radixSort(int a[], int n) {
	int i, bucket, d, factor = 1;

	// 정렬할 자료의 기수, 즉 RADIX에 따라 10개의 버킷을 큐로 생성
	LQueueType* Q[RADIX];  // 버킷 큐의 헤드 포인터를 포인터 배열로 선언
	for (bucket = 0; bucket < RADIX; bucket++)
		Q[bucket] = createLinkedQueue();

	// 키값의 자릿수만큼, 즉 두 번 기수 정렬을 반복 수행
	for (d = 0; d < DIGIT; d++) {
		for (i = 0; i < n; i++)
			enLQueue(Q[(a[i] / factor) % RADIX], a[i]);
		for (bucket = 0, i = 0; bucket < RADIX; bucket++)
			while (!isLQEmpty(Q[bucket]))  a[i++] = deLQueue(Q[bucket]);
		printf("\n\n %d 단계 : ", d + 1);
		for (i = 0; i < n; i++)  printf(" %3d", a[i]);

		factor = factor * RADIX;
	}
}
int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]); 	// list 배열의 원소 개수
	printf("\n정렬할 원소 : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n <<<<< 기수 정렬 수행 >>>>>>");
	radixSort(list, size);  // 기수 정렬 함수 호출

	getchar();  return 0;
}