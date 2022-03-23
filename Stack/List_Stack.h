#pragma once
#include <Windows.h>
#include <string>
using namespace std;


//���߿��Ḯ��Ʈ�� ���� ���ñ����� ������ ������ ��߳���
//������ ���������� ���ϸ���Ʈ������

//stack�� �ּҸ� �����ؼ� �Լ��� ȣ���ϰ� �����ؼ� ���ƿ���
//stack������ ������ ����
//����Լ��� Ÿ�� ���� ��� ������ ����� ���� ����
//�÷��̾ �̵��� ��θ� �Ųٷ� �����ٶ�
//������ ������ ���� ����Ѵ�

template<typename T>
class Stack
{
public:
	struct Node;


public:
	Node* Top() const { return top; }

	bool IsEmpty() const
	{
		return head == nullptr;
	}


	void Push(Node* const node)
	{
		if (head != nullptr)
		{
			Node* tail = head;

			while (tail->Next != nullptr)
			{
				tail = tail->Next;
			}
			tail->Next = node;
		}
		else
		{
			head = node;
		}

		top = node;
		//���� ����Ʈ�� tail�� ������ top�� ����
		//�������� ���ԵȰ��� tail�̹Ƿ�
	}

	Node* Pop() 
	{
		Node* temp = top; //���� ������ tail

		if (head == top)
		{
			head = nullptr;
			top = nullptr;
		}
		else
		{
#pragma region �ٸ� ���
			//Node* tail = head; //������ tail�� �� ���
			//while (tail != nullptr && tail->Next != top)
			//{
			//	tail = tail->Next;
			//}
			//top = tail;
			//
			//temp = tail->Next;
			//temp->Next = nullptr;

#pragma endregion
			Node* tail = head;
			while (tail!= nullptr and tail->Next != top)
			{
				tail = tail->Next;
			}
			top = tail;
			tail->Next = nullptr;

		}
		return temp;

	}

	//this�� �� �ʿ�����ϱ� static���� ����
	static Node* Create(T const data) 
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = nullptr;

		return node;
	}

	int Size()const
	{
		int count = 0;
		Node* current = head;

		while (current != nullptr)
		{
			current = current->Next;
			count++;
		}
		return count;
	}

	static void Destroy(Node* node) 
	{
		delete node;
		node = nullptr;
	}

public:
	struct Node
	{
		Node* Next;

		T Data;
	};

private:
	Node* head = nullptr;
	Node* top = nullptr;

};