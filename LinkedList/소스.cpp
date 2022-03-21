#include<stdio.h>

struct Node
{
	int Data;
	Node* Next;
};
//data�� ������ ������ Node ����
Node* Create(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = NULL;

	return node;
}
//��� ����
void Destroy(Node* node)
{
	delete node;
	node = NULL;
}
//����Ʈ �����͸� �޾� ���� ������ �����ϹǷ� ���������ͷ� �ۼ�
//����Ʈ�� ����ִٸ� ��忡 ��带, ������� �ʴٸ� ���Ͽ� ��带 ����
void Push(Node** head, Node* node)
{
	if ((*head) == NULL)
	{
		*head = node;
	}
	else
	{
		Node* tail = (*head);	//����Ʈ�� ������ ����
		while (tail ->Next != NULL)		//���κ��� ���ϱ��� ��������Ͱ� ���϶����� ����
		{
			tail = tail->Next;
		}
		tail->Next = node;		//������ ��� �����Ϳ� ��� �߰�
	}
}

Node* GetNode(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && --location >= 0)
	{
		current = current->Next;
	}
	return current;
}
int GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->Next;

		count++;
	}
	return count;
}

int main()
{
	Node* list = NULL;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&list, node);
	}

	int count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");

	return 0;
}