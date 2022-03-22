//���� ���� ����Ʈ
/*
�յ��� ��带 ����Ű�� �ּҸ� ��� ������ ����(�����)

*/

#include<stdio.h>

struct  Node
{
	Node*	Prev;
	int		Data;
	Node*	Next;
};

Node* Create(int const data)
{
	Node* node = new Node();
	node->Data = data;
	node->Prev = node->Next = nullptr;

	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = nullptr;
}

void Push(Node ** const head, Node* node)
{
	if ((*head) == nullptr)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = *head;

		while (tail->Next != nullptr)
		{
			tail = tail->Next;
		}
		tail->Next = node;
		node->Prev = tail;
	}
}

void Insert(Node* current, Node* node)
{
	node->Next = current->Next;
	node->Prev = current;

	if (current->Next != nullptr)
		current->Next->Prev = node;

	current->Next = node;
}