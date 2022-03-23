#pragma once
#define MAX_STACK_COUNT 5

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

template<typename T>
class Stack
{
public:
	Stack()
	{
		//원하는 값으로 원하는 사이즈만큼 세팅
		memset(values, 0, sizeof(T) * MAX_STACK_COUNT);
		//ZeroMemory(values, Sizeof(T * MAX_STACK_COUNT);
	}

	void Push(T val)
	{
		//assert는 release 상태에서 줄이 날아가므로 프로그램 작동에 영향을 끼치는 연산을 넣으면 안된다
		assert(top + 1< MAX_STACK_COUNT);

		values[++top] = val;
	}

	T Pop()
	{
		bool b = IsEmpty();
		assert(b == false);

		T val = values[top];
		memset(&values[top], 0, sizeof(T));
		top--;

		return val;
	}
	T Front()
	{
		return values[top];
	}

	T Back()
	{
		assert(top > -1);

		return values[0];
	}


	bool IsEmpty()
	{
		return top < 0 ? true : false;
	}

private:
	int top = -1; //Top of Pointer

	T values[MAX_STACK_COUNT];
};