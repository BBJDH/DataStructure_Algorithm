#include<iostream>
using namespace std;



//함수 템플릿 
template<typename T> void Print(T data)
{
	cout << "함수 : " << data << endl;
}
//템플릿 특수화 : 자료형에 따라 템플릿의 호출을 고정시키기 위해 사용
//예를들면
template<typename T> void Print(int data)
{
	printf("특수화 : %d\n",data);
}
template<typename T> void Print(char data)
{
	printf("특수화 : %c\n", data);
}

int main()
{
	int i = 10;
	Print<int>(i);

	char b = 'A';
	Print<char>(b);

	float t = 20.0f;
	Print<float>(t);



	return 0;
}