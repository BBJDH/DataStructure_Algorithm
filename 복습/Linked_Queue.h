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
		T data = front->Data; //���� ������ ����

		Node* del_Node = front; //������ ��� �ּ� ����
		front = front->Next;	//front �������� �̵�

		delete del_Node;	//����

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
