#pragma once

//�����ڸ� �ۼ��ߴٸ� �Ҹ��ڵ� ���� ������ �ۼ��ؾ��Ѵ�
//��ü�� �Ҵ��ߴٸ� �����ϴ� �ڵ嵵 ������
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

		rear->Next = node; //������ ����
		rear = node;		//������ ����

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


