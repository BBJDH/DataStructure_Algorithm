#include<stdio.h>
#include"List_Stack.h"

int main()
{
	Stack<string> stack;
	stack.Push(Stack<string>::Create("abc"));
	stack.Push(Stack<string>::Create("def"));
	stack.Push(Stack<string>::Create("ghi"));
	stack.Push(Stack<string>::Create("jkl"));


	printf("Size : %d\n", stack.Size());

	int count = stack.Size();
	for (int i = 0; i < count; i++)
	{
		if (stack.IsEmpty() == true)
		{
			break;
		}

		Stack<string>::Node* temp = stack.Pop();
		printf("pop : %s\n", temp->Data.c_str());
		Stack<string>::Destroy(temp);
		if (stack.IsEmpty())
		{
			printf("Stack is empty\n");
			break;
		}
		printf("Top : %s\n", stack.Top()->Data.c_str());

	}

	return 0;
}