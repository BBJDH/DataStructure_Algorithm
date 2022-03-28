#pragma once
/*

����Ʈ�� 
�ڽ��� �ΰ��� ���� �� �ִ� Ʈ��

���� ����Ʈ��, ����Ž��Ʈ�� � ����

STL Map set ->���� ����Ʈ���� ���

��ȭ ���� Ʈ��(Full Binary Tree)
�ڽ��� �� ä���� Ʈ��

���� ���� Ʈ��(Complete Binary Tree)
�ڽ��� ���ʺ��� ä�������� Ʈ��
���� �˻��� ���� ���ʺ��� ä��� �˻��� �Ѵ�

���� ����Ʈ��
���ʰ� �������� ���̰� 1���̸� �ִ� Ʈ��

���� ���� ���� Ʈ��
���ʰ� �������� ���̰� ������ Ʈ��
���������� ���� �˻��� ���� ��� (���Ի����� �Ҹ�)

��ȸ
����
Root Left Right(Pre Order ���)
Root - Left - Right
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]
A - B - C - D - E - F - G ������ ��ȸ

����(In Order)
Left Root Right
���ʺ��� ����
-> ����Ʈ������ ���, ���ڽ��� ���ʺ��� �湮�ؼ� ��
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]

C - B - D - A - F - E - G ������ ��ȸ

(1*2)+(3-4)�� ����Ʈ��
		+
	*		-
1	2		3	4

��ȸ
1*2 + 3-4 (���� ǥ���)

���� (Post Order)
Left Right Root
		A		- [Root]
	B		E
C	D		F	G
[Left]		[Right]

C - D - B - F - G - E - A
-> CPU Decoder ����, ���� ����� ������
(1*2)+(3-4)
=>
		+
	*		-
1	2		3	4       

��ȸ (���α׷� ���� )
1 2 * 3 4 - +  (���� ǥ���)
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


	//�ڵ� ������
	//�Ľ�Į, ����� �빮�� ������ũ
	//�ϰ��� �ְ�
};

