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
		printf("\n%d�ܰ� : ", i + 1);
		for (t = 0; t < size; t++)  printf("%3d ", a[t]);
	}
}

	int main(void) {
		// list �� �迭 �ٲٱ�
		int i, list[5] = { 37, 14, 17, 40, 35 };	// ������ ����
		int size = sizeof(list) / sizeof(list[0]);
		printf("\n������ ���� : ");
		for (i = 0; i < size; i++) 	printf("%d ", list[i]);	// ���� ���� ���� ���
		printf("\n\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");
		SelectionSort(list, size);		// ���� ���� �Լ� ȣ��

		getchar(); return 0;
	}
