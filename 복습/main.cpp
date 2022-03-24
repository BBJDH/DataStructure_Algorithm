#include"Circular_Queue.h"

int main()
{
	Circular_Queue<int> queue(10);
	printf("queue Created, Capacity is %d.\n",queue.GetCapacity());

	int data = 0;
	while (!queue.IsFull())
	{
		queue.Enqueue(data);
		printf("Enqueue : %d, Size : %d, Front : %d, Rear : %d\n", data++, queue.GetSize(),queue.GetFront(),queue.GetRear());

	}
	printf("queue is Full!\n\n");

	while (!queue.IsEmpty())
	{
		printf("Dequeue : %d, Size : %d, Front : %d, Rear : %d\n", queue.Dequeue(), queue.GetSize(), queue.GetFront(), queue.GetRear());

	}
	printf("queue is Empty!\n\n");


	return 0;
}