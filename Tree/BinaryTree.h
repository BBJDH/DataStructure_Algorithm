#pragma once
/*

이진트리 
자식을 두개만 가질 수 있는 트리

수식 이진트리, 이진탐색트리 등에 쓰임

STL Map set ->균형 이진트리로 사용

포화 이진 트리(Full Binary Tree)
자식이 꽉 채워진 트리

완전 이진 트리(Complete Binary Tree)
자식이 왼쪽부터 채워져가는 트리
빠른 검색을 위해 왼쪽부터 채우고 검색을 한다

높이 균형트리
왼쪽과 오른쪽의 깊이가 1차이만 있는 트리

완전 높이 균형 트리
왼쪽과 오른쪽의 깊이가 동일한 트리
마찬가지로 빠른 검색을 위해 사용 (삽입삭제에 불리)

순회
전위
Root Left Right(Pre Order 방법)
Root - Left - Right
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]
A - B - C - D - E - F - G 순으로 순회

중위(In Order)
Left Root Right
왼쪽부터 시작
-> 수식트리에서 사용, 맨자식의 왼쪽부터 방문해서 옴
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]

C - B - D - A - F - E - G 순으로 순회

(1*2)+(3-4)의 수식트리
		+
	*		-
1	2		3	4

순회
1*2 + 3-4 (중위 표기식)

후위 (Post Order)
Left Right Root
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]

C - D - B - F - G - E - A
-> CPU Decoder 구조, 계산기 설계시 유용함
(1*2)+(3-4)
=>
		+
	*		-
1	2		3	4       

순회 (프로그램 실행 )
1 2 * 3 4 - +  (후위 표기식)
*/
template<typename T>
class BTree
{
public:
	struct Node;

public:
	BTree()
	{
	}
	~BTree()
	{
	}
	void PreOrder(Node* node)
	{
		if (node == nullptr)return;

		printf("%c ", node->Data);	//Root
		PreOrder(node->Left);	//Left
		PreOrder(node->Right);	//Right
	}
	void InOrder(Node* node)
	{
		if (node == nullptr)return;

		InOrder(node->Left);	//Left
		printf("%c ", node->Data);	//Root
		InOrder(node->Right);	//Right
	}
	void PostOrder(Node* node)
	{
		if (node == nullptr)return;

		PostOrder(node->Left);	//Left
		PostOrder(node->Right);	//Right
		printf("%c ", node->Data);	//Root
	}

	void Root(Node* node) { root = node; }

private:
	void Destroy(Node* node)
	{
		if (node == nullptr) return;

		Destroy(node->Left);
		Destroy(node->Right);

		DestroyNode(node);
	}


public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = nullptr;

		return node;
	}

	static void DestroyNode(Node* node)
	{
		delete node;
		node = nullptr;
	}


public:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};

private:
	Node* root;


	//코딩 컨벤션
	//파스칼, 상수는 대문자 스네이크
	//일관성 있게
};

