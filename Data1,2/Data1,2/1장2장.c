#include <stdio.h>

int i = 0;
// 순차탐색 알고리즘
int Lsearch(int arr[], int len, int target)
{

	for (i = 0; i < len; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;

}
// 이진탐색 알고리즘
int BSearch(int arr[], int len, int target)
{
	int first = 0; // 탐색 대상의 시작 인덱스 값
	int last = len - 1; // 탐색 대상의 마지막 인덱스 값
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2; // 탐색 대상의 중앙 인덱스 찾기
		if (target == arr[mid]) // 중앙에 저장된 것이 타겟이라면
		{
			return mid; // 탐색 완료!
		}
		else // 타겟이 아니라면 탐색 대상을 반으로 줄임
		{
			if (target < arr[mid])
				last = mid - 1; // 왜 -1을 하였을까?
			else
				first = mid + 1; // 왜 +1을 하였을까?
		}
	}
	return -1; // 찾지 못했을 때 반환되는 값 -1
}
// 재귀함수 기본
void Recursive(int num)
{
	if (num <= 0) {
		return;
	}
	printf("Recursive is call %d \n", num);
	Recursive(num - 1);

}
// 팩토리얼 함수
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

// 피보나치 수열 재귀함수 

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
// 재귀함수를 이용한 이진탐색 알고리즘
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
