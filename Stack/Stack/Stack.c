#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef int element;
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}ArrayStack;	

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//Arraystack ����
void createArryastack(ArrayStack* S) {
	S->top = -1;
}
int isFull(ArrayStack* S) {
	return S->top == MAX_SIZE - 1;
}
int isEmpty(ArrayStack* S) {
	return S->top == -1;
}
//Arraystack push ����	
void Arraypush(ArrayStack* S, element x) {
	if (isFull(S)) {
		printf("[ERROR] Stack is FULL!!\n");
		return error;
	}
	else {
		S->top += 1;
		S->stack[S->top] = x;
	}
}
//Arraystack pop ����
element Arraypop(ArrayStack* S) {
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
//Arraystack peek ����
element Arraypeek(ArrayStack* S) {
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return error;
	}
	else {
		return S->stack[S->top];
	}
}
int main(void) {
	ArrayStack* A;
	createArryastack(&A);
	Arraypush(&A, 10);
	Arraypush(&A, 10);
	Arraypush(&A, 10);
	printf("%d\n", Arraypop(&A));
}
//pop�� ����, error