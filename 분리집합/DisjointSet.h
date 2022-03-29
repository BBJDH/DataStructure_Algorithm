#pragma once
/*
�и� ���� : �������� ��Ұ� ���� ����

->
	1				4
2		3		5		6

�������� �ִٸ� �и������� �ƴϴ�

������: Ʈ�� �������� ���� �׷��� ��Ʈ ��尡 �ٸ� �׷��� ��Ʈ ����� �ڽ����� ����
������ �̶�� �ش� ���� root �ؿ� ����

	1	---------	5
2	3	4		6		7

*/

template<typename T>
class DisjointSet
{
public:
	struct Set;
public:
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = nullptr;

		return set;
	}
	static void DestroySet(Set* set)
	{
		delete set;
		set = nullptr;
	}
	//�θ� Set�� ã�Ƽ� ��ȯ
	static Set* FindSet(Set* set)
	{
		while (set->Parent != nullptr)
		{
			set = set->Parent;
		}
		return set;
	}

	//set�� ������ parent���հ� ������(root) ����(Ʈ��)
	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}
	
public:
	//�����Ϳ� ��带 ���� ������ �� �ִ� ����ü Set
	struct Set
	{
		T Data;
		Set* Parent; //�θ�� ����
	};

};