#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T> 
class Character
{
	//��� ������ ����� �����ϴ°� ���� public �� ����
	//���ø��� ����� ������ ���� �� �ְ� hpp Ȯ���ڰ� �����Ѵ� IDE������ ����� �ν�
public:
	void Set(T name)
	{
		this->name = name;
	}

	void Print()
	{
		cout << "ĳ���� �̸� : " << name << endl;
	}

private:
	T name;
};

class Player : public Character<string>
{
};


class A
{
public:
	//Ŭ���� ���ο��� �ٷ� ����
	//Ŭ���� ���ο� ���Ǹ� ������ �Լ��� �ڵ����� inline ó���ȴ�
	void Test() {}		//inline
	inline void Test2();	//�ܺ����Ǵ� inline ȭ ������ �ʿ��ϴ�
};

void A::Test2()
{

}