#include<stdio.h>
#include<stack>
using namespace std;

void main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (s.empty() == false)
	{
		int top = s.top();
		printf("Top : %d\n", top);

		s.pop();
	}
	//배열 또는 리스트로 스택을 구현 가능
}