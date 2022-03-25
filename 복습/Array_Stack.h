#pragma once
#include<iostream>
#include<assert.h>
template<typename T>
class Array_Stack
{
public:
	Array_Stack(int const size) :arr{ nullptr }, top{ -1 }, size{ size }
	{
		arr = new T[size]{};
	
	}
	~Array_Stack()
	{
		delete[] arr;
		arr = nullptr;
	}
	void Push(T data)
	{
		assert(top + 1 < size);
		arr[++top] = data;
	}
	T Pop()
	{
		assert(!IsEmpty());
		return arr[top--];
	}
	bool IsEmpty() { return top == -1; }
	bool IsFull() { return top + 1 == size; }
	int GetSize() { return size; }
	
	void Print_All()
	{
		std::cout << "Stack Print All" << std::endl;

		int ex_top = this->top;

		while (ex_top!=-1)
		{
			std::cout << "Print : " << arr[ex_top--] << std::endl;
		}
		std::cout << "Stack End" << std::endl;

	}

private:
	T* arr;
	int top;
	int size;
};
