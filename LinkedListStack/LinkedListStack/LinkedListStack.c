#include<stdio.h>
#include<stdlib.h>

//��� ����ü ����
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

//���� ����ü ���� head�� top���� ����� �� ��
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create() {
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

int isEmpty(Stack* S) {
	return S->top == NULL;
}

int isFull(Stack* S) {
	return 0;
}
//���� ���� ������ ���� ������ ��尡 �ǰ� �ֱٿ� ������ ���� ù��° ��尡 �ȴ�
//���� ���� ������ ����� link���� null
// �ܼ����Ḯ��Ʈ�� ù��° ��忡 �����ϴ� ����� �����ϴ�.
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

//�ܼ� ���Ḯ��Ʈ�� �� ó�� ��带 �����ϴ� ���� ���� 
//top�� ������ ������ temp�� ����Ű�� ��(temp.link)�� ���� ����Ų��
element pop(Stack* S) {
	stackNode* temp; element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
		//return ERROR;
	}
	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
		return e;
	}
}

element peek(Stack* S) {
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return;
		//return ERROR;
	}
	else
		return S->top->data;
}

void print(Stack* S){
	
	printf("�ֻ���� ����%d", S->top);
	}

int main(void) {
	Stack* S = create();
	push(S, 10);
	pop(S);
	print(S);

}