#include <stdio.h>






BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;
	int expLen = strlen(exp);
	int i;
	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();
		if (isdigit(exp[i])) { // 피연산자라면...
			SetData(pnode, exp[i] - '0'); // 문자를 정수로 바꿔서 저장
		}
		else { // 연산자라면...
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // 단말 노드라면
		return GetData(bt);
	op1 = GetData(GetLeftSubTree(bt)); // 첫 번째 피연산자
	op2 = GetData(GetRightSubTree(bt)); // 두 번째 피연산자
	switch (GetData(bt)) // 연산자를 확인하여 연산을 짂행
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}
