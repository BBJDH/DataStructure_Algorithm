#pragma once

template<typename T>class Circular_Queue
{
public:
	Circular_Queue(int capacity) :capacity{ capacity }
	{
		datas = new T[capacity + 1];
	}
	~Circular_Queue()
	{
		delete[] datas;
		datas = nullptr;
	}

	int Capacity()
	{
		return capacity;
	}
	int Front()
	{
		return front;
	}
	int Rear()
	{
		return rear;
	}
	void Enqueue(T data) //데이터 삽입
	{
		int position = 0;

		if (rear == capacity)
		{
			position = rear;
			rear = 0;
		}
		else
		{
			position = rear++; //대입 후 1증가
		}

		datas[position] = data;
	}
	T Dequeue()
	{
		int position = front;

		if (front == capacity)
			front = 0;
		else
		{
			front++;
		}
		return datas[position];
	}

	bool IsEmpty()
	{
		return front == rear;
	}

	bool IsFull()
	{
		return front - rear == 1 or rear - front == capacity;
	}

	int Size()
	{
		if(front < rear)
			return rear - front;
		return rear + (capacity - front)+1;
	}


private:
	T* datas;
	int capacity;
	int front = 0;
	int rear = 0;

};