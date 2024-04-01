#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element;		// ���� ����(element)�� �ڷ����� char�� ���� 

typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����


// ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;     // ���� ��带 top�� ���� ����
	top = temp;           // top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);  // ���� top�� ���� ��ȯ
	}
}

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}
// ���� ǥ��� ������ ����ϴ� ����
element evalPostfix(char* exp) {
	int opr1, opr2, value, i = 0;
	// char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
	int length = strlen(exp);
	char symbol;

	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			value = symbol - '0';
			push(value);
		}
		else {
			opr2 = pop();
			opr1 = pop();
			// ���� opr1�� opr2�� ���� symbol�� ����� �����ڸ� ����
			switch (symbol) {
			case '+': push(opr1 + opr2); break;
			case '-': push(opr1 - opr2); break;
			case '*': push(opr1 * opr2); break;
			case '/': push(opr1 / opr2); break;
			}
		}
	}
	// ���� exp�� ���� ó���� ��ģ �� ���ÿ� ���� �ִ� ������� pop�Ͽ� ��ȯ
	return pop();
}

int main(void) {
	int result;
	char* express = "35*62/-";
	printf("���� ǥ��� : %s", express);

	result = evalPostfix(express);
	printf("\n\n���� ��� => %d\n", result);

	getchar();  return 0;
}