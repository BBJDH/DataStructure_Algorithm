#pragma once
/*
비선형 : 데이터를 순차적으로 나열하지 않은 데이터
트리, 그래프


트리(Root) - 가지(Branch) - 잎(leaf)노드

깊이 : Root에서부터 가장 낮은 Leaf까지의 깊이
   
         (깊이)
    A       (0)
    |
  B G I     (1)      B G I는 A 를 부모로 하는 형제 노드(Siblings)
 _| | |
| | | |
C D H J     (2)      C와 D는 B를 부모로 하는 형제 노드
 _|   |
| |   |
E F   K     (3)

Root   : A노드
Branch : B,G,I,D,J
Leaf   : C,H,E,F,K
A~E 까지의 경로(PASS) : A-B-D-E
레벨 : 깊이가 같은 노드들
위 트리느 깊이가 3인 트리다

트리를 표현하는 방법(3가지)
중첩괄호 방식(Root가 시작될 때 왼쪽에 괄호가 열려야한다)
->  (A(B(C)(D(E)(F)))(G(H))(I(J(K))))
집합 표현 방식
일반 집합 표현 방식과 동일
들여쓰기 방식
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

트리 구현 방법
N-LINK 표현방식
             
0레벨 링크                 [0 1 2 ...N개 노드]
                          |     Branch       |
1레벨 링크  [0 1 2...N개 노드]             [0 1 2...N개 노드]
형제노드끼리 묶어서 개수만큼 Link 형태로 구현
->고정 메모리 배열로 사용할 경우 메모리 낭비가 심하다(자식이 몇이 될지 차수가 얼마나될지 알 수없음)
->프로그램의 요구에 따라 동적할당이나 링크드 리스트로 구현 시 구현이 비교적 복잡해진다

Left-Right-Sibling (자식의 갯수가 가변인 경우)
왼쪽에는 자식을 두고 오른쪽에는 형식을 두는 방법
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
    {//left 부터 형제는 right로 추가
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
