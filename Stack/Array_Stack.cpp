#include "Array_Stack.h"

int main()
{
	Stack<int> stack;
	stack.Push(10);

	stack.Push(20);
	stack.Pop();

	stack.Push(12);
	stack.Pop();

	stack.Push(4);

	while (stack.IsEmpty() == false)
	{
		printf("%d\n", stack.Pop());
	}
	//디버그 조사식 : 디버그 -> 창 -> 조사식
	//원하는 변수명, 보고싶은 갯수 (배열처럼)


	return 0;
}