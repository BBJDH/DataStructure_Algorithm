#include<stdio.h>

struct Node
{
	int Data;
	Node* Next;
};
//data를 보유한 임의의 Node 생성
Node* Create(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = NULL;

	return node;
}
//노드 삭제
void Destroy(Node* node)
{
	delete node;
	node = NULL;
}
//리스트 포인터를 받아 안의 내용을 수정하므로 이중포인터로 작성
//리스트가 비어있다면 헤드에 노드를, 비어있지 않다면 테일에 노드를 삽입
void Push(Node** head, Node* node)
{
	if ((*head) == NULL)
	{
		*head = node;
	}
	else
	{
		Node* tail = (*head);	//리스트의 헤드부터 시작
		while (tail ->Next != NULL)		//헤드로부터 테일까지 노드포인터가 널일때까지 추적
		{
			tail = tail->Next;
		}
		tail->Next = node;		//테일의 노드 포인터에 노드 추가
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