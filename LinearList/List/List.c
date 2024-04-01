#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// �迭 ����ü ����
typedef int element;
typedef struct {
	int list[MAX_SIZE];
	int size;
}ArrayListType;

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L) {
	L->size = 0;
}

//�迭 ����Ʈ����
ArrayListType* initlist() {
	ArrayListType* L; 
	L = (ArrayListType*)malloc(sizeof(ArrayListType));
	L->size = 0;
	return L;
}

// ����Ʈ�� ��������� 1 �׷��� ������ 0 ��ȯ
int is_empty(ArrayListType* L) {
	return L->size == 0;
}

// ����Ʈ�� ���� �������� 1 �׷��� ������ 0�� ��ȯ
int is_full(ArrayListType* L) {
	return L->size == MAX_SIZE;
}

// ù��° ��ġ�� �߰�
// ��ȭ�������� �˻� 
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

// pos ��ġ�� �߰�
/* 1. �迭�� ��ȭ�������� �˻�
2. pos�� ������ ��ġ���� �˻�
3. ������ ���� ��ĭ�� �ڷ� �̵�
�ڿ� ���� �տ� �� i+1�� ���� i�� ��
�̵� Ƚ�� = n-k+1 */
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

// ������ ��ġ�� �߰�
// ��ȭ�������� �˻�
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_SIZE) {
		error("����Ʈ�� ���� á���ϴ�");
	}
	L->list[L->size+1] = item;
}

// ���� �Լ�
/* 1. �迭�� ��ȭ�������� �˻�
2. pos�� ������ ��ġ���� �˻�
3. pos ���� ���� ������ i+1�� ���� i��
 �̵� Ƚ�� n-k */

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

// pos �� ��ġ ��ȯ
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ����");
	return L->list[pos];
}

// replace �Լ�
void replace(ArrayListType* L, int pos, element item)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	L->list[pos] = item;
}
//�迭�� ���� �Լ�
int get_length(ArrayListType* L)
{
	printf("length = %d", L->size);
	return L->size;
	
}

// �迭 �ʱ�ȭ �Լ�
void clear(ArrayListType* L)
{
	L->size = 0;
}

// ����Ʈ ��� �Լ�
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d ", L->list[i]);
	printf("\n");
}

int main(void) { 
	
	

}
//���� �Ҵ�
