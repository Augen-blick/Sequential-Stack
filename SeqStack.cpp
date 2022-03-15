#include <iostream>
#include "SeqStack.h"

using namespace std;

bool symmetry(ElemType str[]);

int main()
{
	//定义栈
	SqStack *s1;

	//初始化栈
	InitStack(s1);

	//赋值
	for (int i = 0; i < 10; i++)
	{
		Push(s1, i + 2);
	}

	//取栈顶元素
	int top;
	GetTop(s1, top);
	cout << "s1栈顶元素是：" << top << endl;

	//销毁栈
	DestroyStack(s1);

	//检测symmetry函数
	int str[] = { 1,2,3,4,5,4,3,2,1 };
	bool key = symmetry(str);
	if (key)
		cout << "str是一个对称串" << endl;
	else
		cout << "str不是一个对称串" << endl;

	return 0;
}

bool symmetry(ElemType str[])							//判断str是否为对称串
{
	int i,j;
	j = sizeof(str) / sizeof(str[0]);
	ElemType e;
	SqStack* s;
	InitStack(s);
	for (i = 0; i < j; i++)				//进栈
		Push(s, str[i]);
	for (i = 0; i < j/2; i++)
	{
		Pop(s, e);									//出栈
		if (str[i] != e)
		{
			DestroyStack(s);
			return false;
		}
	}
	DestroyStack(s);
	return true;
}