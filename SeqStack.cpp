#include <iostream>
#include "SeqStack.h"

using namespace std;

bool symmetry(ElemType str[]);

int main()
{
	//����ջ
	SqStack *s1;

	//��ʼ��ջ
	InitStack(s1);

	//��ֵ
	for (int i = 0; i < 10; i++)
	{
		Push(s1, i + 2);
	}

	//ȡջ��Ԫ��
	int top;
	GetTop(s1, top);
	cout << "s1ջ��Ԫ���ǣ�" << top << endl;

	//����ջ
	DestroyStack(s1);

	//���symmetry����
	int str[] = { 1,2,3,4,5,4,3,2,1 };
	bool key = symmetry(str);
	if (key)
		cout << "str��һ���Գƴ�" << endl;
	else
		cout << "str����һ���Գƴ�" << endl;

	return 0;
}

bool symmetry(ElemType str[])							//�ж�str�Ƿ�Ϊ�Գƴ�
{
	int i,j;
	j = sizeof(str) / sizeof(str[0]);
	ElemType e;
	SqStack* s;
	InitStack(s);
	for (i = 0; i < j; i++)				//��ջ
		Push(s, str[i]);
	for (i = 0; i < j/2; i++)
	{
		Pop(s, e);									//��ջ
		if (str[i] != e)
		{
			DestroyStack(s);
			return false;
		}
	}
	DestroyStack(s);
	return true;
}