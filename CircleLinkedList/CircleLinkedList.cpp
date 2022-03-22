#include<stdio.h>

struct Node
{
	Node* Prev;
	int	Data;
	Node* Next;
};

Node* Create(int data)
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

void Push(Node** head, Node* node)
{
	if (*head == nullptr)
	{
		*head = node;
		(*head)->Next = *head;
		(*head)->Prev = *head;
	}
	else
	{
		Node* tail = (*head)->Prev;

		tail->Next->Prev = node;
		tail->Next = node;

		node->Next = (*head);
		node->Prev = tail;
	}
}

void Insert(Node* current, Node* node)
{
	node->Next = current->Next;
	node->Prev = current;

	current->Next->Prev = node;
	current->Next = node;
}

void Remove(Node** head, Node* remove)
{
	if (*head == remove)
	{
		(*head)->Prev->Next = remove->Next;
		(*head)->Next->Prev = remove->Prev;

		*head = remove->Next;
	}
	else
	{
		Node* temp = remove;

		remove->Prev->Next = temp->Next;
		remove->Next->Prev = temp->Prev;

	}

	remove->Prev = remove->Next = nullptr;
}
//getnode, getnodecount, 메인 테스트코드 작성

Node* GetNode(Node* const head, int location)
{
	Node*  current = head;
	while ((--location)>0 and current->Next !=nullptr)
	{
		current = current->Next;
	}
	return current;
}
int GetNodeCount(Node* const head)
{
	int count = 0;
	Node* current = head;

	while (current->Next != head and current->Next != nullptr)
	{
		count++;
		current = current->Next;

	}
	return count;
}
void PrintList(Node* const head, int const count)
{
	printf("Print List\n");
	Node* current = head;
	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d \n",i, current->Data);
		current = current->Next;
	}
	printf("End\n");
}


int main()
{
	Node* head = nullptr;

	for (int i = 0; i < 5; i++)
	{
		Node* new_node = Create(i);
		Push(&head,new_node);
	}

	int count = GetNodeCount(head);

	PrintList(head, count);

	return 0;
}