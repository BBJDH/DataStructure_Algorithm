#include<iostream>
using namespace std;



//�Լ� ���ø� 
template<typename T> void Print(T data)
{
	cout << "�Լ� : " << data << endl;
}
//���ø� Ư��ȭ : �ڷ����� ���� ���ø��� ȣ���� ������Ű�� ���� ���
//�������
template<typename T> void Print(int data)
{
	printf("Ư��ȭ : %d\n",data);
}
template<typename T> void Print(char data)
{
	printf("Ư��ȭ : %c\n", data);
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