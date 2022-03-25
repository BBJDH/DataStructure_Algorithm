#pragma once
#include<iostream>

template<typename T>
class Linked_Queue
{
private:
	struct Node;


public:
	Linked_Queue() : front{ nullptr }, rear{nullptr}
	{}
	~Linked_Queue()
	{
		if (IsEmpty() == false)
			Dequeue_all();
			
	}

	void EnQueue(T const data)
	{
		Node* node = new Node;
		node->Data = data;
		node->Next = nullptr;

		if (IsEmpty())
		{
			front = node;
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
		T data = front->Data; //리턴 데이터 보관

		Node* del_Node = front; //삭제할 노드 주소 보관
		front = front->Next;	//front 다음노드로 이동

		delete del_Node;	//삭제

		return data;
	}
	bool IsEmpty()
	{
		return front == nullptr;
	}
	int GetSize()
	{
		int count = 0;

		Node* start = front;
		while (start !=nullptr)
		{
			start = start->Next;
			count++;
		}
		return count;
	}
	void Dequeue_all()
	{
		std::cout << "Dequeue All.. Size is " <<GetSize()<< std::endl;
		while (IsEmpty() == false)
		{
			std::cout << "Dequeue : " << DeQueue() << std::endl;
		}
	}

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
