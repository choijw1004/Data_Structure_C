#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// �迭 ����ü ����
typedef int element;
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

//�迭�̱⶧���� top �� -1 index ����
void create(Stack* S) {
	S->top = -1;
}

//0���� �����ϱ� ����
// ����Ʈ�� ���� �������� 1 �׷��� ������ 0�� ��ȯ
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1;
}
// ����Ʈ�� ��������� 1 �׷��� ������ 0 ��ȯ
int isEmpty(Stack* S) {
	return S->top == -1;
}
void push(Stack* S, element x) {
	if (isFull(S)) {
		printf("[ERROR] Stack is FULL!!\n");
		return;
	}
	else {
		S->top += 1;
		S->stack[S->top] = x;
		//S->stack[++(S->top)] = x;
	}
}
//�迭�̱⶧���� �����ϴ� ������ ��ġ�� �ʾƵ� �ȴ�.
element pop(Stack* S) {
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
	}
	else {
		element e = S->stack[S->top];
		S->top -= 1;
		return e;
	}
}
element peek(Stack* S) {
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
	}
	else {
		return S->stack[S->top];
	}
}
void print(Stack* S) {
	printf("pop: %d", S->stack[S->top]);
}
//error

int main(void) {
	Stack* stack;
	stack = (Stack*)malloc(sizeof(Stack*));
	push(stack, 10);
	push(stack, 10);
	push(stack, 110);
	int e = pop(stack);
	print(stack);
	printf("�ֻ�ܿ��� pop�� ���� %d �Դϴ�", e);
	
}