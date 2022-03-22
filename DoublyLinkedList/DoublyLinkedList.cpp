//���� ���� ����Ʈ
/*
�յ��� ��带 ����Ű�� �ּҸ� ��� ������ ����(�����)

*/

#include<stdio.h>

struct  Node
{
	Node*	Prev;		//���� ��� ������
	int		Data;
	Node*	Next;		//���� ��� ������
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

void Push(Node ** const head, Node* const node)//�� �ڿ� ��� �߰�
{
	if ((*head) == nullptr)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = *head;

		while (tail->Next != nullptr)		//����Ʈ�� tail ���� ã�´�
		{
			tail = tail->Next;
		}
		tail->Next = node;		//tail�� �ڿ� ���� ���� �����͸� ���
		node->Prev = tail;
	}
}

void Insert(Node* const current, Node* const node)	//current ��� �ڿ� ����
{
	node->Next = current->Next;
	node->Prev = current;			//���� �߰��� ����� ����� ������ ����

	if (current->Next != nullptr)		// �߰��� ����� ������尡 ������ ������� �����͵� ����
		current->Next->Prev = node;

	current->Next = node;		//�߰��� ����� ������尡 ������ ������� ������ ����
}

void InsertHead(Node** const head, Node* const node) //head �տ� ��� �߰�
{
	if (*head == nullptr)		//��尡 ���������(�� ����Ʈ)
		*head = node;
	else
	{
		node->Next = *head;		//�ص�տ� ��� �߰�
		*head = node;
	}
}

void Remove(Node** const head, Node* remove)		//remove ��� ����
{
	if (*head == remove)		//�����ϴ� ��尡 head ���
	{
		*head = remove->Next;		//head�� �������� �ڸ��� ä�� ���� ��� ������ ���

		if (*head != nullptr)		//����� prev ������ �ʱ�ȭ
			(*head)->Prev = nullptr;

		remove->Prev = nullptr;		//������ ��� �� �� ���� ����
		remove->Next = nullptr;
	}
	else
	{		//������ ��尡 �����ġ�� �ƴ϶��(��� ���̿� �ִٸ�)
		Node* current = remove;
		remove->Prev->Next = current->Next;		//������带 ������� �޳��� �̾��ش�
		if (remove->Next != nullptr)		//������� �޳�尡 ������� �ʴٸ�
			remove->Next->Prev = current->Prev;		//�޳�忡���� �ճ�� �����͸� �������ش�
	}

	remove->Prev = nullptr;
	remove->Next = nullptr;
}

Node* GetNode(Node* const head, int location)
{
	Node* current = head;

	while (current != nullptr && (--location)>= 0)
	{
		current = current->Next;
	}
	return current;
}

int GetNodeCount(Node* const head)
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

int main()
{
	Node* head = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&head,node);
	}

	Node* newNode = nullptr;
	{
		newNode = Create(-1);
		InsertHead(&head, newNode);

		newNode = Create(-2);
		InsertHead(&head, newNode);
	}


	int count = 0;
	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	newNode = Create(100);
	Push(&head, newNode);

	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	Node* current = GetNode(head, 2);
	newNode = Create(1000);

	Insert(current, newNode);

	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, 0);

		if (current != nullptr)
		{
			Remove(&head, current);
			Destroy(current);
		}
	}


	return 0;
}