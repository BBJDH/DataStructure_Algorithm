#pragma once
template<typename T>
class Linked_Queue
{
private:
	struct Node;


public:
	Linked_Queue() :head{ nullptr }, front{ nullptr }, rear{nullptr}
	{}
	~Linked_Queue();

	void EnQueue(T const data)
	{
		Node* node;
		node->Data = data;
		node->Next = nullptr;

		if (front == nullptr)
		{
			front = node;
			front->Next = node;
			rear = node;
		}
		else
		{
			rear->Next = node;
			rear = node;
		}
	}
	T DeQueue()
	{
		T data = rear->data;

	}
	bool IsEmpty()
	{}
private:
	struct Node
	{
		T Data;
		Node* Next;
	};
private:
	Node* front;
	Node* rear;

};
