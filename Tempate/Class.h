#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T> 
class Character
{
	//멤버 변수는 숨기고 참조하는게 많은 public 을 위로
	//템플릿은 선언과 구현을 나눌 수 있게 hpp 확장자가 존재한다 IDE에서는 헤더로 인식
public:
	void Set(T name)
	{
		this->name = name;
	}

	void Print()
	{
		cout << "캐릭터 이름 : " << name << endl;
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
	//클래스 내부에서 바로 정의
	//클래스 내부에 정의를 포함한 함수는 자동으로 inline 처리된다
	void Test() {}		//inline
	inline void Test2();	//외부정의는 inline 화 선언이 필요하다
};

void A::Test2()
{

}