#pragma once
/*
1. ���� ǥ��� �� ������ �����ʿ������� �������� �о� ���δ�.
2. ���Ŀ��� ���� �����ʿ� �ִ� �����ڰ� ��Ʈ ��尡 �ȴ�.
	-���� ǥ�⿡�� �׻� ���� �����ʿ� �ִ� ��ū�� �׻� ������
3. ��ū�� �����ڶ�� ���� ��� �̸�, ������ ���� ������ 2���� ��ū��
	�����ʰ� ������ �ڽĳ��
4. ��, ���� ��ū�� �����ؼ� �����ڶ�� �� ��ū�� ���� ��������� 
	���� Ʈ���� �ϼ��� ���Ŀ� �о ��ū�� ���� �ڽ� ��尡 ��
5. ��ū�� ���ڶ�� ���� ���
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

