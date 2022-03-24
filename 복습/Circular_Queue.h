#pragma once
#include<stdio.h>
template<typename T>
class Circular_Queue
{
public:
	Circular_Queue(int capacity) :capacity(capacity), front{ 0 }, rear{0}
	{
		list = new T[capacity + 1];
	}
	~Circular_Queue()
	{
		//TODO: ���빰�� �ִ� ��� Dequeue�� ���빰 ���� �� �ʱ�ȭ
		delete[] list;
	}
	//Enqueue
	void Enqueue(T data)
	{
		//rear�� capacity�� ������
		if (rear==capacity)
		{
			list[rear] = data;
			rear = 0;

			return;
		}
		list[rear++] = data;
		
	}
	//Dequeue
	T Dequeue()
	{
		T data =list[front];
		if (front >= capacity)
		{
			front = 0;
		}
		else
		{
			front++;
		}

		return data;
	}
	//IsFull
	bool IsFull()
	{
		return front - rear == 1 or rear - front == capacity;
	}
	//IsEmpty
	bool IsEmpty()
	{
		return front == rear;
	}
	int GetSize()
	{
		if (rear >= front)
			return rear - front;
		else
			return rear + (capacity - front) + 1;
	}
	int GetFront() { return front; }
	int GetRear() { return rear; }
	int GetCapacity() { return capacity; }

private:
	T* list;
	int const capacity;
	int front;
	int rear;
};

