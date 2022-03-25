#include"Circular_Queue.h"
#include"Linked_Queue.h"
#include"Array_Stack.h"
#include"List_Stack.h"

#include<iostream>

using namespace std;
int main()
{
#pragma region Cirular_Queue test
	//Circular_Queue<int> queue(10);
//printf("queue Created, Capacity is %d.\n",queue.GetCapacity());

//int data = 0;
//while (!queue.IsFull())
//{
//	queue.Enqueue(data);
//	printf("Enqueue : %d, Size : %d, Front : %d, Rear : %d\n", data++, queue.GetSize(),queue.GetFront(),queue.GetRear());

//}
//printf("queue is Full!\n\n");

//while (!queue.IsEmpty())
//{
//	printf("Dequeue : %d, Size : %d, Front : %d, Rear : %d\n", queue.Dequeue(), queue.GetSize(), queue.GetFront(), queue.GetRear());

//}
//printf("queue is Empty!\n\n");  
#pragma endregion

#pragma region Linked_Queue test

	//Linked_Queue<string> queue;

	//queue.EnQueue("abc");
	//queue.EnQueue("def");
	//queue.EnQueue("ghi");
	//queue.EnQueue("jkl");
	//queue.EnQueue("mno");

	//queue.Dequeue_all();

	//std::cout << std::endl;

#pragma endregion
	
#pragma region Array_Stack test
					//Array_Stack<int> arr_stack(10);

	//int data = 100;
	//while (arr_stack.IsFull() == false)
	//{
	//	arr_stack.Push(data++);
	//}
	//arr_stack.Print_All();

#pragma endregion

	List_Stack<std::string> stack;

	stack.push("abc");
	stack.push("def");
	stack.push("ghi");
	stack.push("jkl");
	stack.push("mno");


	while (!stack.IsEmpty())
	{
		std::cout << "Pop : " << stack.Pop() << std::endl;
	}



	return 0;
}