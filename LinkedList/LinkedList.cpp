#include<stdio.h>

struct Node
{
	int Data;
	Node* Next;
};
//data�� ������ ������ Node ����
Node* Create(int const data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = nullptr;

	return node;
}
//��� ����
void Destroy(Node* node)
{
	delete node;
	node = nullptr;
}
//����Ʈ �����͸� �޾� ���� ������ �����ϹǷ� ���������ͷ� �ۼ�
//����Ʈ�� ����ִٸ� ��忡 ��带, ������� �ʴٸ� ���Ͽ� ��带 ����
void Push(Node ** const head, Node* const node)
{
	if ((*head) == nullptr)
	{
		*head = node;
	}
	else
	{
		Node* tail = (*head);	//����Ʈ�� ������ ����
		while (tail ->Next != nullptr)		//���κ��� ���ϱ��� ��������Ͱ� ���϶����� ����
		{
			tail = tail->Next;
		}
		tail->Next = node;		//������ ��� �����Ϳ� ��� �߰�
	}
}
//����Ʈ�� location ��° ������ ��带 ������
Node* GetNode(Node* const head, int location)		//head �������� ������ ���� �ʿ��ϹǷ� ����������
{
	Node* current = head;

	while (current != nullptr && --location >= 0)
	{
		current = current->Next;
	}
	return current;
}
//����Ʈ ������ ����
int GetNodeCount(Node * const head)		//head �������� ������ ���� �ʿ��ϹǷ� ����������
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
//����Ʈ�� head�� ��� ����
void InsertHead(Node** const head, Node* const node)		//head�����Ͱ� ������ �� �����Ƿ� ���������͸� ���ڷ� ����
{
	if (*head == nullptr)
	{
		*head = node;
	}
	else
	{
		node->Next = *head;
		*head = node;

	}
}

void Remove(Node** const head, Node* const remove)	//head�����Ͱ� ������ �� �����Ƿ� ���������͸� ���ڷ� ����
{
	if (*head == remove) //����Ʈ ũ�Ⱑ 1���� ���
	{
		*head = remove->Next;
	}
	else
	{	//*head �� ���������ΰ�� �ƹ��͵� ���� ����
		Node* current = *head;
		while (current != nullptr && current->Next != remove)
		{
			current = current->Next;
		}

		if (current != nullptr)
			current->Next = remove->Next;
	}
}
//List Print
void PrintList(Node * const head)		//head �������� ������ ���� �ʿ��ϹǷ� ����������
{
	int const size = GetNodeCount(head);
	for (int i = 0; i < size; i++)
	{
		Node* current = GetNode(head, i);
		//����Ʈ�� i ��° ���� ����

		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");
}

int main()
{
	Node* list = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&list, node);			//��� ���� �� Ǫ��
	}

	int count = GetNodeCount(list);	//����Ʈ�� ����� ����

	//����Ʈ ���
	PrintList(list);

	printf("\n");
	printf("GetNode form List, 3st\n");		

	Node* temp = GetNode(list, 3);		//3��° ����Ʈ �˻�
	printf("List[%d] : %d\n\n", 3, temp->Data);		//����Ʈ

	Node* newNode = Create(-1);
	InsertHead(&list, newNode);		//��� �տ� -1 ����

	PrintList(list);		//����Ʈ

	Remove(&list, temp);		//����Ʈ���� 3 ����

	PrintList(list);		//����Ʈ

	return 0;
}

//vector �� List�� ����
//vector�� �ּҰ� ���ӵǾ� �ִ�
//����Ʈ�� ��尡 ���� ����� �����͸� ����

//���� �ڷ���
//�߰�, ������ �ð��� �����ɸ���
//������ ������ ������ ���� �ø����� ������ ����� ���� �����͸� ��� �ű��
//������ �ǹ���(�ѹ� �ε�ǰ� ������ ���°�, ���Ի����� �������� Ž���� ������)

//����Ʈ �ڷ���
//�׳� �߰��� ����ְ� ����
//�÷��̾�, ���Ի����� ����� ������Ʈ��
//���� ����ȸ�翡�� ������ ���� �� ���ִ� �κ�
//

//�����ʹ� �ش� ������ �����Ѽ� �� ������ ����ϴ� ���� ����
//���� �����͸� ���ڷ� ����Ͽ� �Լ��� �ۼ��ϸ� �ش������Ͱ� �������� ���� ���/���� ���������� �����ʹ� �������
//���� �����͸� ���ڷ� ����Ͽ� �Լ��� �ۼ��ϸ� ������ ���� ��� ���������ϸ� ������ ���� ���� �����ϴ� 
//�������� ������ ������ ����Ѵٸ� ����������, �Լ��ȿ��� ������ ������ ������ �ʿ��ϴٸ� ���� �����͸� �Լ� ���ڷ� ���
//������� �����ͷ� ��ü�� �����Ͽ� ���Ϲ������Ҷ�