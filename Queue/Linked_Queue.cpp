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
���ť(����� ���������� �޾Ƽ� ����Ҷ�)
���� - Ŭ���̾�Ʈ

�߾� ť�� �ǰ������� ������
ĳ���͸��� ���ť��(���� ĳ���ʹ� ���� ���, ���� ĳ���ʹ� �ǰ� ���)
��� ó���� �����̰� �ִ°�� ���

�켱���� ť



*/