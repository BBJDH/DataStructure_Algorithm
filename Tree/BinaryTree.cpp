#include<stdio.h>
#include"BinaryTree.h"

int main()
{
	typedef BTree<char> Tree;

	Tree tree;

	Tree::Node* A = Tree::CreateNode('A');
	Tree::Node* B = Tree::CreateNode('B');
	Tree::Node* C = Tree::CreateNode('C');
	Tree::Node* D = Tree::CreateNode('D');
	Tree::Node* E = Tree::CreateNode('E');
	Tree::Node* F = Tree::CreateNode('F');
	Tree::Node* G = Tree::CreateNode('G');

	/*				A
	*			B		E
	*		C	D		F	G
	*
	*/
	tree.Root(A);

	A->Left = B;
	A->Right = E;
	
	B->Left = C;
	B->Right = D;

	E->Left = F;
	E->Right = G;

	printf("PreOrder\n");
	tree.PreOrder(A);
	printf("\n\n");
	
	printf("InOrder\n");
	tree.InOrder(A);
	printf("\n\n");

	printf("PostOrder\n");
	tree.PostOrder(A);
	printf("\n\n");

	return 0;
}