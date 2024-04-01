#include <stdio.h>
void intervalSort(int a[], int begin, int end, int interval) {
	int i, j, item;
	for (i = begin + interval; i <= end; i = i + interval) {
		item = a[i];
		for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
			a[j + interval] = a[j];
		a[j + interval] = item;
	}
}

void shellSort(int a[], int size) {
	int i, interval;
	interval = size / 2;
	while (interval >= 1) {
		for (i = 0; i < interval; i++)  intervalSort(a, i, size - 1, interval);
		printf("\n interval=%d >> ", interval);
		for (i = 0; i < size; i++) printf("%d ", a[i]);
		printf("\n");
		interval = interval / 2;
	}
}

int main(void) {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]); 	// list 배열의 원소 개수
	printf("\n정렬할 원소 : ");
	for (int i = 0; i < size; i++)  printf("%3d ", list[i]);
	printf("\n\n<<<<<<<<<< 셸 정렬 수행 >>>>>>>>>>\n");
	shellSort(list, size);  // 쉘 정렬 함수 호출

	getchar();  return 0;
}