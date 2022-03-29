#pragma once
/*
분리 집합 : 공통적인 요소가 없는 집합

->
	1				4
2		3		5		6

교집합이 있다면 분리집합이 아니다

합집합: 트리 구조에서 현재 그룹의 루트 노드가 다른 그룹의 루트 노드의 자식으로 연결
합집합 이라면 해당 집합 root 밑에 연결

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
	//부모 Set을 찾아서 반환
	static Set* FindSet(Set* set)
	{
		while (set->Parent != nullptr)
		{
			set = set->Parent;
		}
		return set;
	}

	//set의 집합을 parent집합과 합집합(root) 연결(트리)
	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}
	
public:
	//데이터와 노드를 같이 관리할 수 있는 구조체 Set
	struct Set
	{
		T Data;
		Set* Parent; //부모와 연결
	};

};