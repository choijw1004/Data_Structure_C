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
		if (isdigit(exp[i])) { // �ǿ����ڶ��...
			SetData(pnode, exp[i] - '0'); // ���ڸ� ������ �ٲ㼭 ����
		}
		else { // �����ڶ��...
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
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // �ܸ� �����
		return GetData(bt);
	op1 = GetData(GetLeftSubTree(bt)); // ù ��° �ǿ�����
	op2 = GetData(GetRightSubTree(bt)); // �� ��° �ǿ�����
	switch (GetData(bt)) // �����ڸ� Ȯ���Ͽ� ������ ����
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
