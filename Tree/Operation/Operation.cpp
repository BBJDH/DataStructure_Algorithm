#include<stdio.h>
#include"../BinaryTree.h"

#include <string>
using namespace std;

void Expression(const char* postfix, BTree<char>::Node** node)
{
	char* str = const_cast<char*>(postfix);
	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] = '\0';

	switch (token)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	{
		*node = BTree<char>::CreateNode(token);

		Expression(postfix, &(*node)->Right);
		Expression(postfix, &(*node)->Left);
		break;
	}
	default:
	{
		//읽은 토큰이 피연산자인 경우
		*node = BTree<char>::CreateNode(token);
	}
		break;
	}
}

int Evaluate(BTree<char>::Node* node)
{
	if (node == nullptr)return 0;

	switch (node->Data)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	{
		int left = Evaluate(node->Left);
		int right = Evaluate(node->Right);

		switch (node->Data)
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
		case '%': return left % right;

		}
	}
	break;
	default:
	{
		char temp[4];
		memset(temp, 0, sizeof(temp));

		temp[0] = node->Data;
		return atoi(temp);
	}
	break;
	}
	return 0;
}

int main()
{
	//(3*4)-(1+4)
	//34* 14+ -

	string postfix = "34*14+-";

	BTree<char>::Node* root = nullptr;
	Expression(postfix.c_str(), &root);

	BTree<char> tree;
	tree.Root(root);

	printf("PreOrder\n");
	tree.InOrder(root);
	printf("\n\n");


	printf("PostOrder\n");
	tree.PostOrder(root);
	printf("\n\n");

	printf("Evaluate : %d\n", Evaluate(root));

	return 0;
}