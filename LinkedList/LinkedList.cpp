#include<stdio.h>

struct Node
{
	int Data;
	Node* Next;
};
//data를 보유한 임의의 Node 생성
Node* Create(int const data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = nullptr;

	return node;
}
//노드 삭제
void Destroy(Node* node)
{
	delete node;
	node = nullptr;
}
//리스트 포인터를 받아 안의 내용을 수정하므로 이중포인터로 작성
//리스트가 비어있다면 헤드에 노드를, 비어있지 않다면 테일에 노드를 삽입
void Push(Node ** const head, Node* const node)
{
	if ((*head) == nullptr)
	{
		*head = node;
	}
	else
	{
		Node* tail = (*head);	//리스트의 헤드부터 시작
		while (tail ->Next != nullptr)		//헤드로부터 테일까지 노드포인터가 널일때까지 추적
		{
			tail = tail->Next;
		}
		tail->Next = node;		//테일의 노드 포인터에 노드 추가
	}
}
//리스트의 location 번째 참조된 노드를 가져옴
Node* GetNode(Node* const head, int location)		//head 포인터의 역참조 값만 필요하므로 단항포인터
{
	Node* current = head;

	while (current != nullptr && --location >= 0)
	{
		current = current->Next;
	}
	return current;
}
//리스트 사이즈 측정
int GetNodeCount(Node * const head)		//head 포인터의 역참조 값만 필요하므로 단항포인터
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
//리스트의 head에 노드 삽입
void InsertHead(Node** const head, Node* const node)		//head포인터가 변동될 수 있으므로 이중포인터를 인자로 선언
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

void Remove(Node** const head, Node* const remove)	//head포인터가 변동될 수 있으므로 이중포인터를 인자로 선언
{
	if (*head == remove) //리스트 크기가 1개인 경우
	{
		*head = remove->Next;
	}
	else
	{	//*head 가 널포인터인경우 아무것도 하지 않음
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
void PrintList(Node * const head)		//head 포인터의 역참조 값만 필요하므로 단항포인터
{
	int const size = GetNodeCount(head);
	for (int i = 0; i < size; i++)
	{
		Node* current = GetNode(head, i);
		//리스트의 i 번째 원소 접근

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
		Push(&list, node);			//노드 생성 후 푸시
	}

	int count = GetNodeCount(list);	//리스트의 사이즈를 측정

	//리스트 출력
	PrintList(list);

	printf("\n");
	printf("GetNode form List, 3st\n");		

	Node* temp = GetNode(list, 3);		//3번째 리스트 검색
	printf("List[%d] : %d\n\n", 3, temp->Data);		//프린트

	Node* newNode = Create(-1);
	InsertHead(&list, newNode);		//헤드 앞에 -1 삽입

	PrintList(list);		//프린트

	Remove(&list, temp);		//리스트에서 3 삭제

	PrintList(list);		//프린트

	return 0;
}

//vector 와 List의 차이
//vector는 주소가 연속되어 있다
//리스트는 노드가 다음 노드의 포인터를 보유

//벡터 자료형
//추가, 삭제가 시간이 오래걸린다
//기존의 공간이 꽉차면 다음 늘리려는 공간을 만들고 기존 데이터를 모두 옮긴다
//게임의 건물들(한번 로드되고 변경이 없는것, 삽입삭제는 느리지만 탐색이 빠르다)

//리스트 자료형
//그냥 중간에 끼어넣고 제거
//플레이어, 삽입삭제가 빈번한 오브젝트들
//실제 게임회사에서 면접시 물어 볼 수있는 부분
//

//포인터는 해당 공간을 가리켜서 그 공간을 사용하는 것이 목적
//단항 포인터를 인자로 사용하여 함수를 작성하면 해당포인터가 역참조한 값을 사용/수정 가능하지만 포인터는 사라진다
//이중 포인터를 인자로 사용하여 함수를 작성하면 역참조 값을 사용 수정가능하며 포인터 또한 수정 가능하다 
//포인터의 역참조 값만을 사용한다면 단항포인터, 함수안에서 포인터 변수의 수정이 필요하다면 이중 포인터를 함수 인자로 사용
//예를들면 포인터로 객체를 생성하여 리턴받으려할때