#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

// ������ ���� 1���� �迭�� ���� ������ ������ ����ü�� ��� ����
typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;

// ���� ������ �����ϴ� ����
heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// ������ item�� �����ϴ� ����
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// ������ ��Ʈ�� �����Ͽ� ��ȯ�ϴ� ����
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

// 1���� �迭 ������ ������ ����ϴ� ����
void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}
int main(void) {
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 200);
	insertHeap(heap, 192);
	insertHeap(heap, 63);
	insertHeap(heap, 72);
	insertHeap(heap, 185);
	insertHeap(heap, 60);
	insertHeap(heap, 62);
	insertHeap(heap, 16);
	insertHeap(heap, 52);
	insertHeap(heap, 37);
	insertHeap(heap, 22);
	insertHeap(heap, 11);
	insertHeap(heap, 5);
	insertHeap(heap, 38);

	printHeap(heap);

	//n = heap->heap_size;
	for (i = 1; i <= 3; i++) {
		item = deleteHeap(heap);
		printf("\n delete : [%d]\n ", item);
	}
	printHeap(heap);


	getchar();  return 0;
}