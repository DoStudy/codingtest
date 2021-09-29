#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	/**
	 * LinkedList Test - 맨 앞의 노드 삭제
	 */
	{
		// Insert Test
		LinkedList<int> linkedList;
		linkedList.Insert(5);
		linkedList.Insert(6);
		linkedList.Insert(7);

		// Delete Test
		linkedList.Delete(5);

		// Print test
		linkedList.PrintLinkedList();
	}

	/**
	 * LinkedList Test - 중간 노드 삭제
	 */
	{
		// Insert Test
		LinkedList<int> linkedList;
		linkedList.Insert(5);
		linkedList.Insert(6);
		linkedList.Insert(7);

		// Delete Test
		linkedList.Delete(6);

		// Print test
		linkedList.PrintLinkedList();
	}

	/**
	 * LinkedList Test - 마지막 노드 삭제
	 */
	{
		// Insert Test
		LinkedList<int> linkedList;
		linkedList.Insert(5);
		linkedList.Insert(6);
		linkedList.Insert(7);

		// Delete Test
		linkedList.Delete(7);

		// Print test
		linkedList.PrintLinkedList();
	}

	/**
	 * Stack Test
	 */
	{
		Stack<int> stack;
		stack.Push(1);
		stack.Push(2);

		assert(stack.Top() == 2);
		stack.Pop();

		assert(stack.Top() == 1);
		stack.Pop();

		assert(stack.IsEmpty());
	}

	/**
	 * Queue Test
	 */
	{
		Queue<char> queue;
		queue.Push('a');
		queue.Push('b');
		queue.Push('c');

		assert(queue.Front() == 'a');
		assert(queue.Rear() == 'c');
		queue.Pop();
		assert(queue.Front() == 'b');
		assert(queue.Rear() == 'c');
		queue.Pop();
		assert(queue.Front() == 'c');
		assert(queue.Rear() == 'c');
		queue.Pop();
	}
}
