#include <stdio.h>
#define MAX 30

extern int size;
int sorted[MAX];				// ���Ҹ� �����ϸ鼭 ������ ���·� ������ �迭 ����

void merge(int a[], int m, int middle, int n) {
	int i, j, k, t;
	i = m;							// ù ��° �κ������� ���� ��ġ ����
	j = middle + 1;				// �� ��° �κ������� ���� ��ġ ����
	k = m;						// �迭 sorted�� ���ĵ� ���Ҹ� ������ ��ġ ����

	while (i <= middle && j <= n) {
		if (a[i] <= a[j])
			sorted[k++] = a[i++];
		else
			sorted[k++] = a[j++];
	} // while

	if (i > middle)
		for (t = j; t <= n; t++, k++) sorted[k] = a[t];
	else
		for (t = i; t <= middle; t++, k++)	sorted[k] = a[t];

	for (t = m; t <= n; t++) 	a[t] = sorted[t];

	printf("\n ���� ���� >> ");
	for (t = 0; t < size; t++) printf("%4d ", a[t]);
}

void mergeSort(int a[], int m, int n) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle);		// �� �κп� ���� ���� �۾� ����
		mergeSort(a, middle + 1, n);	// �� �κп� ���� ���� �۾� ����
		merge(a, m, middle, n);			// �κ����տ� ���Ͽ� ���İ� ���� �۾� ���� 
	}
}

int size;
int main(void) {
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = sizeof(list) / sizeof(list[0]); 	// list �迭�� ���� ����
	printf("\n ������ ���� >> ");
	for (i = 0; i < size; i++) printf("%4d ", list[i]);
	printf("\n\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");
	mergeSort(list, 0, size - 1);   // ���� ���� �Լ� ȣ��

	getchar();  return 0;
}