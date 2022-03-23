#include<stdio.h>

struct Node
{
	Node* Prev;
	int	Data;
	Node* Next;
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

void Push(Node** const head, Node* const node)
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
		
		(*head)->Prev = node;
		tail->Next = node;

		node->Next = (*head);
		node->Prev = tail;
	}
}

void Insert(Node* const current, Node* const node)
{
	node->Next = current->Next;
	node->Prev = current;

	current->Next->Prev = node;
	current->Next = node;
}

void Remove(Node** const head, Node* const remove)
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
	while ( current->Next !=nullptr and (--location) >= 0 )
	{
		current = current->Next;
	}
	return current;
}
int GetNodeCount(Node* const head)
{
	if (head == nullptr)
		return 0;
	if (head == head->Prev)
		return 1;

	int count = 1;
	Node* current = head;
	Node* tail = head->Prev;
	while (current != tail)
	{
		current = current->Next;
		count++;
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
	Node* head = nullptr;	//List 선언

	for (int i = 0; i < 1; i++)		//List 노드 삽입
	{
		Node* new_node = Create(i);
		Push(&head,new_node);
	}

	int count = GetNodeCount(head);		//사이즈 측정

	PrintList(head, count);			//출력

	return 0;
}
