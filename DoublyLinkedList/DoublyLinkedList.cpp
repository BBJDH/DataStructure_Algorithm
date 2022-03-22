//이중 연결 리스트
/*
앞뒤의 노드를 가리키는 주소를 모두 가지고 있음(양방향)

*/

#include<stdio.h>

struct  Node
{
	Node*	Prev;		//이전 노드 포인터
	int		Data;
	Node*	Next;		//다음 노드 포인터
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

void Push(Node ** const head, Node* const node)//맨 뒤에 노드 추가
{
	if ((*head) == nullptr)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = *head;

		while (tail->Next != nullptr)		//리스트의 tail 까지 찾는다
		{
			tail = tail->Next;
		}
		tail->Next = node;		//tail의 뒤에 삽입 서로 포인터를 등록
		node->Prev = tail;
	}
}

void Insert(Node* const current, Node* const node)	//current 노드 뒤에 삽입
{
	node->Next = current->Next;
	node->Prev = current;			//새로 추가될 노드의 양방향 포인터 세팅

	if (current->Next != nullptr)		// 추가된 노드의 다음노드가 참조한 이전노드 포인터도 수정
		current->Next->Prev = node;

	current->Next = node;		//추가된 노드의 이전노드가 참조할 다음노드 포인터 수정
}

void InsertHead(Node** const head, Node* const node) //head 앞에 노드 추가
{
	if (*head == nullptr)		//헤드가 비어있으면(빈 리스트)
		*head = node;
	else
	{
		node->Next = *head;		//해드앞에 노드 추가
		*head = node;
	}
}

void Remove(Node** const head, Node* remove)		//remove 노드 제거
{
	if (*head == remove)		//제거하는 노드가 head 라면
	{
		*head = remove->Next;		//head에 없어지고 자리를 채울 다음 노드 포인터 등록

		if (*head != nullptr)		//등록후 prev 포인터 초기화
			(*head)->Prev = nullptr;

		remove->Prev = nullptr;		//제거할 노드 앞 뒤 연결 해제
		remove->Next = nullptr;
	}
	else
	{		//삭제될 노드가 헤드위치가 아니라면(노드 사이에 있다면)
		Node* current = remove;
		remove->Prev->Next = current->Next;		//이전노드를 삭제노드 뒷노드와 이어준다
		if (remove->Next != nullptr)		//삭제노드 뒷노드가 비어있지 않다면
			remove->Next->Prev = current->Prev;		//뒷노드에서의 앞노드 포인터를 변경해준다
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