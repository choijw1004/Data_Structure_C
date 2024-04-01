#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// 배열 구조체 정의
typedef int element;
typedef struct {
	int list[MAX_SIZE];
	int size;
}ArrayListType;

// 리스트 초기화 함수
void init(ArrayListType* L) {
	L->size = 0;
}

//배열 리스트생성
ArrayListType* initlist() {
	ArrayListType* L; 
	L = (ArrayListType*)malloc(sizeof(ArrayListType));
	L->size = 0;
	return L;
}

// 리스트가 비어있으면 1 그렇지 않으면 0 반환
int is_empty(ArrayListType* L) {
	return L->size == 0;
}

// 리스트가 가득 차있으면 1 그렇지 않으면 0을 반환
int is_full(ArrayListType* L) {
	return L->size == MAX_SIZE;
}

// 첫번째 위치에 추가
// 포화상태인지 검사 
void insert_first(ArrayListType* L, element item) {
	int i;
	if (is_full(L)) {
		error("List is Full!");
	}
	else {
		for (i = 0; i < L->size; i++)
			L->list[i + 1] = L->list[i];
		L->list[0] = item;
		L->size++;
	}
}

// pos 위치에 추가
/* 1. 배열이 포화상태인지 검사
2. pos가 적절한 위치인지 검사
3. 끝에서 부터 한칸씩 뒤로 이동
뒤에 값이 앞에 값 i+1의 값이 i의 값
이동 횟수 = n-k+1 */
void insert(ArrayListType* L, int pos, element item) {
	int i;
	if (is_full(L))
		error("List is Full!");
	else if ((pos < 0) || (pos > L->size))
		error("index Error");
	else {
		for (i = (L->size - 1); i >= pos; i--)
			L->list[i + 1] = L->list[i];
		L->list[pos] = item;
		L->size++;
	}
}

// 마지막 위치에 추가
// 포화상태인지 검사
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_SIZE) {
		error("리스트가 가득 찼습니다");
	}
	L->list[L->size+1] = item;
}

// 삭제 함수
/* 1. 배열이 포화상태인지 검사
2. pos가 적절한 위치인지 검사
3. pos 에서 부터 앞으로 i+1의 값이 i값
 이동 횟수 n-k */

element delete(ArrayListType* L, int pos) {
	int i;
	element item;
	if (is_empty(L))
		error("List is Empty!");
	else if ((pos < 0) || (pos >= L->size))
		error("inedex Error");
	else {
		item = L->list[pos];
		for (i = pos; i < L->size - 1; i++)
			L->list[i] = L->list[i + 1];
		L->size--;
		return item;
	}
}

// pos 의 위치 반환
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치오류");
	return L->list[pos];
}

// replace 함수
void replace(ArrayListType* L, int pos, element item)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	L->list[pos] = item;
}
//배열의 길이 함수
int get_length(ArrayListType* L)
{
	printf("length = %d", L->size);
	return L->size;
	
}

// 배열 초기화 함수
void clear(ArrayListType* L)
{
	L->size = 0;
}

// 리스트 출력 함수
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d ", L->list[i]);
	printf("\n");
}

int main(void) { 
	
	

}
//동적 할당
