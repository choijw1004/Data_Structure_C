#include <stdio.h>
#include <stdio.h>

int i = 0;  //�o���� �ܰ� ��¿� ����

// �־��� �κ����� �ȿ��� �Ǻ��� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(int a[], int begin, int end, int size) {
	int  pivot, L, R, t, temp;
	L = begin;
	R = end;
	pivot = (begin + end) / 2;	// �߰��� ��ġ�� ���Ҹ� �Ǻ� ���ҷ� ����
	printf("\n [%d�ܰ� : pivot = %d ] \n", ++i, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) {					// L�� R ������ �ڸ� ��ȯ
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			// L�� �Ǻ��� ���, ����� �Ǻ��� ��ġ(R)�� �ٽ� ����!
			if (L == pivot)	pivot = R;
		} // if(L<R)
	} // while(L<R)
	// (L=R)�� �� ���, 
	// �� �̻� ������ �� �����Ƿ� R ���ҿ� �Ǻ� ������ �ڸ��� ��ȯ�Ͽ� ������
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++)  printf("%4d", a[t]);	// ������ ���� ���� ���
	printf("\n");
	return R;	// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ ��ȯ
}

void quickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end, size);	// �Ǻ��� ��ġ�� ���� ���� ��ġ ����
		quickSort(a, begin, p - 1, size);		// �Ǻ��� ���� �κ����տ� ���� �� ������ ���ȣ��
		quickSort(a, p + 1, end, size);		// �Ǻ��� ������ �κ����տ� ���� �� ������ ���ȣ��
	}
}


int main(void) {
	int list[10] = { 8, 1, 4, 9, 6, 3, 5, 2, 7, 0 }, i = 0;
	int size = sizeof(list) / sizeof(list[0]); 	// list �迭�� ���� ����
	printf("\n������ ���� : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n<<<<<<<<<< �� ���� ���� >>>>>>>>>>\n");
	quickSort(list, 0, size - 1, size);  // �� ���� �Լ� ȣ��

	getchar();  return 0;
}
