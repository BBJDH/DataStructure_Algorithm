#pragma once
#include<assert.h>
template<typename T>
class List_Stack
{
	//TODO: 스택
public:
	List_Stack() :head{ nullptr }, top{ nullptr }
	{}
	~List_Stack()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	void push(T data)
	{
		Node* node = new Node;
		node->Next = nullptr;
		node->Data = data;

		if (head == nullptr)
		{
			head = node;
			top = node;
		}
		else
		{
			top->Next = node;
			top = node;
		}
	}
	T Pop()
	{
		assert(head != nullptr);

		T data = top->Data;
		Node* new_top = head;

		if (head->Next == nullptr)
		{
			delete top;
			top = nullptr;
			head = nullptr;
			return data;
		}



		while (new_top->Next != top ) //새로운 top 탐색
		{
			new_top = new_top->Next;
		}
		
		delete top;
		top = nullptr;
		top = new_top;
		top->Next = nullptr;
		return data;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}

private:
	struct Node
	{
		T	  Data;
		Node* Next;
	};

	Node* head;
	Node* top;
};

