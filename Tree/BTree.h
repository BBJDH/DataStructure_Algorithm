#pragma once
/*
1. 후위 표기로 된 수식을 오른쪽에서부터 왼쪽으로 읽어 들인다.
2. 수식에서 제일 오른쪽에 있는 연산자가 루트 노드가 된다.
	-후위 표기에서 항상 제일 오른쪽에 있는 토큰은 항상 연산자
3. 토큰이 연산자라면 가지 노드 이며, 다음에 따라 나오는 2개의 토큰은
	오른쪽과 왼쪽의 자식노드
4. 단, 다음 토큰이 연속해서 연산자라면 이 토큰을 통해 만들어지는 
	하위 트리가 완성된 이후에 읽어낸 토큰이 왼쪽 자식 노드가 됨
5. 토큰이 숫자라면 리프 노드
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
		DestroyTree(root);
	}

	void Root(Node* node) { root = node; }

	void PreOrder(Node* node)
	{
		if (node == nullptr)return;

		printf(" %c", node->Data);	//Root
		PreOrder(node->Left);	//Left
		PreOrder(node->Right);	//Right
	}
	void InOrder(Node* node)
	{
		if (node == nullptr)return;

		InOrder(node->Left);	//Left
		printf(" %c", node->Data);	//Root
		InOrder(node->Right);	//Right
	}
	void PostOrder(Node* node)
	{
		if (node == nullptr)return;

		PostOrder(node->Left);	//Left
		PostOrder(node->Right);	//Right
		printf(" %c", node->Data);	//Root
	}

private:
	void DestroyTree(Node* node)
	{
		if (node == nullptr)
			return;

		DestroyTree(node->Left);
		DestroyTree(node->Right);

		Destroy(node);	//PostOrder
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = nullptr;
		return node;
	}

	static void Destroy(Node* node)
	{
		delete node;
		node = nullptr;
	}
public:
	struct Node
	{
		Node* Left;
		Node* Right;

		T Data;
	};
private:
	Node* root;
};

