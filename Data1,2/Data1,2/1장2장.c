#include <stdio.h>

int i = 0;
// ����Ž�� �˰���
int Lsearch(int arr[], int len, int target)
{

	for (i = 0; i < len; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;

}
// ����Ž�� �˰���
int BSearch(int arr[], int len, int target)
{
	int first = 0; // Ž�� ����� ���� �ε��� ��
	int last = len - 1; // Ž�� ����� ������ �ε��� ��
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2; // Ž�� ����� �߾� �ε��� ã��
		if (target == arr[mid]) // �߾ӿ� ����� ���� Ÿ���̶��
		{
			return mid; // Ž�� �Ϸ�!
		}
		else // Ÿ���� �ƴ϶�� Ž�� ����� ������ ����
		{
			if (target < arr[mid])
				last = mid - 1; // �� -1�� �Ͽ�����?
			else
				first = mid + 1; // �� +1�� �Ͽ�����?
		}
	}
	return -1; // ã�� ������ �� ��ȯ�Ǵ� �� -1
}
// ����Լ� �⺻
void Recursive(int num)
{
	if (num <= 0) {
		return;
	}
	printf("Recursive is call %d \n", num);
	Recursive(num - 1);

}
// ���丮�� �Լ�
int Factorial(int i)
{
	if (i = 0) {
		return 1;
	}
	else {
		return i * Factorial(i - 1);
	}
	return 0;
}

// �Ǻ���ġ ���� ����Լ� 

int Fibo(int n)
{
	printf("func call %d %d \n", n, i);
	i++;
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}
// ����Լ��� �̿��� ����Ž�� �˰���
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int count = 0;
int BSearchRecursive(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;
	mid = (first + last) / 2;
	if (arr[mid] == target) {
		count++;
		printf("count = %d", count);
		
		return mid;
	}
	else if (arr[mid] > target)
		return BSearchRecursive(arr, first, mid - 1, target);
	else
		return BSearchRecursive(arr, mid + 1, last, target);
}

void HanoiTower(int n, char from, char tmp, char to)
{
	if (n == 1) {
		printf("Disk1: % c -> % c \n", from, to);
	}
	else
	{
		HanoiTower(n - 1, from, to, tmp);
		printf("Disk % d: % c -> % c \n", n, from, to);
		HanoiTower(n - 1, tmp, from, to);
	}
}

int f1(int n) {

	if (n <= 0)

		return 0;

	else if (n <= 2)

		return n;

	else

		return f1(n - 3) + f1(n - 2) + f1(n - 1);


}
int main() {
	int x =f1(4);
	printf("%d", x);
}
