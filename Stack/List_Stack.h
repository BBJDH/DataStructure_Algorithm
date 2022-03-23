#pragma once
#include <Windows.h>
#include <string>
using namespace std;


//이중연결리스트를 통한 스택구성은 스택의 본질과 어긋난다
//구현은 가능하지만 단일리스트가최적

//stack에 주소를 저장해서 함수를 호출하고 저장해서 돌아오는
//stack프레임 구조를 가짐
//재귀함수를 타고 들어가는 경우 스택을 사용해 값을 추적
//플레이어가 이동한 경로를 거꾸로 보여줄때
//순서를 뒤집을 때에 사용한다

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
		//연결 리스트의 tail과 스택의 top은 같다
		//마지막에 삽입된것이 tail이므로
	}

	Node* Pop() 
	{
		Node* temp = top; //나갈 예정인 tail

		if (head == top)
		{
			head = nullptr;
			top = nullptr;
		}
		else
		{
#pragma region 다른 방법
			//Node* tail = head; //삭제후 tail이 될 노드
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

	//this콜 할 필요없으니까 static으로 개방
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