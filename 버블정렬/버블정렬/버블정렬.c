#include <stdio.h>
void bubbleSort(int a[], int size) {
	int i, j, t, temp;

	for (i = size - 1; i > 0; i--) {
		printf("\n %d�ܰ�>>", size - i);
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			printf("\n\t");
			for (t = 0; t < size; t++) printf("%3d ", a[t]);
		}
	}
}

int main(void) {
	int i, list[8] = { 4, 7, 3, 1, 5, 8, 2, 6 };   // ������ ���� 
	int size = sizeof(list) / sizeof(list[0]);
	printf("\n������ ���� : ");
	for (i = 0; i < size; i++)  printf("%d ", list[i]); // ���� ���� ���� ���
	printf("\n\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");
	bubbleSort(list, size);      // ���� ���� �Լ� ȣ��

	getchar();  return 0;
}