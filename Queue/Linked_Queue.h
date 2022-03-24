#pragma once

//생성자를 작성했다면 소멸자도 같이 쌍으로 작성해야한다
//객체를 할당했다면 삭제하는 코드도 쌍으로
template<typename T>
class Linked_Queue
{
private:
	struct Node;


public:

	~Linked_Queue()
	{
		while (IsEmpty() == false)
		{
			Dequeue();
		}
	}
	void Enqueue(T data)
	{
		Node* node = new Node();
		node->Data = data;
		
		if (front == nullptr)
		{
			front = node;
			rear = node;

			count++;
			return;
		}

		rear->Next = node; //삽입전 꼬리
		rear = node;		//꼬리로 삽입

		count++;
	}
	T Dequeue()
	{
		Node* node = front;
		T val = front->Data;

		if (front->Next == nullptr)
			front = rear = nullptr;
		else
			front = front->Next;

		count--;
		delete node;
		node = nullptr;

		return val;
	}

	bool IsEmpty()
	{
		return front == nullptr;
	}
	int Count() { return count; }

private:
	struct Node
	{
		T Data;
		Node* Next;
	};

private:
	Node* front = nullptr;
	Node* rear = nullptr;
	int count = 0;
};


