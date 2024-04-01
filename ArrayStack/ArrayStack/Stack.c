#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// 배열 구조체 정의
typedef int element;
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

//배열이기때문에 top 은 -1 index 관련
void create(Stack* S) {
	S->top = -1;
}

//0에서 시작하기 때문
// 리스트가 가득 차있으면 1 그렇지 않으면 0을 반환
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1;
}
// 리스트가 비어있으면 1 그렇지 않으면 0 반환
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
//배열이기때문에 삭제하는 과정은 거치지 않아도 된다.
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
	printf("최상단에서 pop된 값은 %d 입니다", e);
	
}