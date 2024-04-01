#include <stdio.h>
void SelectionSort(int a[], int size) {
	int i, j, t, min, temp;

	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		printf("\n%d단계 : ", i + 1);
		for (t = 0; t < size; t++)  printf("%3d ", a[t]);
	}
}

	int main(void) {
		// list 수 배열 바꾸기
		int i, list[5] = { 37, 14, 17, 40, 35 };	// 정렬할 원소
		int size = sizeof(list) / sizeof(list[0]);
		printf("\n정렬할 원소 : ");
		for (i = 0; i < size; i++) 	printf("%d ", list[i]);	// 정렬 전의 원소 출력
		printf("\n\n<<<<<<<<<< 선택 정렬 수행 >>>>>>>>>>\n");
		SelectionSort(list, size);		// 선택 정렬 함수 호출

		getchar(); return 0;
	}
