#include <iostream>
#include "LinkedList.h"

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
}
