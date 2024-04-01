#include <stdio.h>

void insertionSort(int a[], int size) {
	int i, j, t, temp;

	for (i = 1; i < size; i++) {
		temp = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > temp)) {
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = temp;
		printf("\n %d�ܰ� : ", i);
		for (t = 0; t < size; t++) printf("%3d ", a[t]);
	}
}

int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 }; // ������ ���� 
	int size = sizeof(list) / sizeof(list[0]); 	// list �迭�� ���� ����
	printf("\n������ ���� : ");
	for (i = 0; i < size; i++)  printf("%d ", list[i]); // ���� ���� ���� ���
	printf("\n\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");
	insertionSort(list, size);  // ���� ���� �Լ� ȣ��
	getchar();  return 0;
}