#include<stdio.h>
#include"Linked_Queue.h"

int main()
{
	Linked_Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	printf("Size : %d\n", queue.Count());

	while (queue.IsEmpty() == false)
	{
		printf("Data : %d\n", queue.Dequeue());
	}

	return 0;
}

/*
명령큐(명령을 순차적으로 받아서 사용할때)
서버 - 클라이언트

중앙 큐에 피격정보가 들어오면
캐릭터마다 명령큐에(때린 캐릭터는 어택 모션, 맞은 캐릭터는 피격 모션)
명령 처리에 딜레이가 있는경우 사용

우선순위 큐



*/