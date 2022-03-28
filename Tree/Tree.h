#pragma once
/*
���� : �����͸� ���������� �������� ���� ������
Ʈ��, �׷���


Ʈ��(Root) - ����(Branch) - ��(leaf)���

���� : Root�������� ���� ���� Leaf������ ����
   
         (����)
    A       (0)
    |
  B G I     (1)      B G I�� A �� �θ�� �ϴ� ���� ���(Siblings)
 _| | |
| | | |
C D H J     (2)      C�� D�� B�� �θ�� �ϴ� ���� ���
 _|   |
| |   |
E F   K     (3)

Root   : A���
Branch : B,G,I,D,J
Leaf   : C,H,E,F,K
A~E ������ ���(PASS) : A-B-D-E
���� : ���̰� ���� ����
�� Ʈ���� ���̰� 3�� Ʈ����

Ʈ���� ǥ���ϴ� ���(3����)
��ø��ȣ ���(Root�� ���۵� �� ���ʿ� ��ȣ�� �������Ѵ�)
->  (A(B(C)(D(E)(F)))(G(H))(I(J(K))))
���� ǥ�� ���
�Ϲ� ���� ǥ�� ��İ� ����
�鿩���� ���
A============
    B========
        C====
        D====
            E
            F
    G========
        H====
    I========   
        J====
            K

Ʈ�� ���� ���
N-LINK ǥ�����
             
0���� ��ũ                 [0 1 2 ...N�� ���]
                          |     Branch       |
1���� ��ũ  [0 1 2...N�� ���]             [0 1 2...N�� ���]
������峢�� ��� ������ŭ Link ���·� ����
->���� �޸� �迭�� ����� ��� �޸� ���� ���ϴ�(�ڽ��� ���� ���� ������ �󸶳����� �� ������)
->���α׷��� �䱸�� ���� �����Ҵ��̳� ��ũ�� ����Ʈ�� ���� �� ������ ���� ����������

Left-Right-Sibling (�ڽ��� ������ ������ ���)
���ʿ��� �ڽ��� �ΰ� �����ʿ��� ������ �δ� ���
               [Data]
            [Child] [Sibling]
            |
        [Data]                 [Data]
   [Child] [Sibling]  => [Child] [Sibling]
      |
    [Data]
[Child] [Sibling]

*/

template<typename T>
class Tree
{
public:
    struct  Node;
    
public:


    void AddChild(Node* parent, Node* child)
    {//left ���� ������ right�� �߰�
        if (parent->LeftChild == nullptr)
        {
            parent->LeftChild = child;
        }
        else
        {
            Node* node = parent->LeftChild;
            while (node->RightSibling != nullptr)
            {
                node = node->RightSibling;
            }
            node->RightSibling = child;
        }
    }

    void PrintNode(Node* node, int depth)
    {
        for (int i = 0; i < depth; i++)
            printf("==");
        printf("%c\n", node->Data);
        
        if (node->LeftChild != nullptr)
            PrintNode(node->LeftChild, depth + 1);

        if (node->RightSibling != nullptr)
            PrintNode(node->RightSibling, depth);

    }
    static Node* CreateNode(T data)
    {
        Node* node = new Node();
        node->Data = data;
        node->LeftChild = node->RightSibling = nullptr;
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

        Node* LeftChild;
        Node* RightSibling;
    };

};
