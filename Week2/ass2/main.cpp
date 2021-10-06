#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNode.h"

using namespace ass2;

int main()
{
	{
		TreeNode<int> n(std::make_unique<int>(2));

		std::shared_ptr<TreeNode<int>> parent = std::make_shared<TreeNode<int>>(std::make_unique<int>(5));
		TreeNode<int> n2(parent, std::make_unique<int>(2));
	}

	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(10));
		tree.Insert(std::make_unique<int>(10));
	}

	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(9));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(2));
		tree.Insert(std::make_unique<int>(7));
		tree.Insert(std::make_unique<int>(11));
		tree.Insert(std::make_unique<int>(12));

		assert(tree.Search(6)); // true
		assert(tree.Search(9)); // true
		assert(tree.Search(4)); // true
		assert(tree.Search(2)); // true
		assert(tree.Search(7)); // true
		assert(tree.Search(11)); // true
		assert(tree.Search(12)); // true
		assert(!tree.Search(15)); // true
		assert(!tree.Search(16)); // true
		assert(!tree.Search(17)); // true
		assert(!tree.Search(18)); // true
	}

	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(10));

		bool bSearched = tree.Search(10); // true
		bSearched = tree.Search(15); // false
	}

	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(9));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(2));
		tree.Insert(std::make_unique<int>(7));
		tree.Insert(std::make_unique<int>(11));
		tree.Insert(std::make_unique<int>(12));

		tree.Delete(11);
	}

	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(12));
		tree.Insert(std::make_unique<int>(7));

		tree.Delete(12);
	}

	{
		BinarySearchTree<int> tree;

		tree.Insert(std::make_unique<int>(10));
		tree.Insert(std::make_unique<int>(15));
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(19));
		tree.Insert(std::make_unique<int>(20));
		tree.Insert(std::make_unique<int>(17));
		tree.Insert(std::make_unique<int>(12));

		std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

		assert(v.size() == 8);
		assert(v[0] == 4);
		assert(v[1] == 5);
		assert(v[2] == 10);
		assert(v[3] == 12);
		assert(v[4] == 15);
		assert(v[5] == 17);
		assert(v[6] == 19);
		assert(v[7] == 20);

		bool bSearched = tree.Search(15);
		assert(bSearched);

		bool bDeleted = tree.Delete(6);
		assert(!bDeleted);

		bDeleted = tree.Delete(100);
		assert(!bDeleted);

		bDeleted = tree.Delete(15);
		assert(bDeleted);

		v = tree.TraverseInOrder(tree.GetRootNode().lock());

		assert(v.size() == 7);
		assert(v[0] == 4);
		assert(v[1] == 5);
		assert(v[2] == 10);
		assert(v[3] == 12);
		assert(v[4] == 17);
		assert(v[5] == 19);
		assert(v[6] == 20);

		bSearched = tree.Search(15);
		assert(!bSearched);
	}

	{
		bool bDelete = false;
		bool bSearch = false;
		BinarySearchTree<int> tree;
		std::vector<int> traverseResult;

		bDelete = tree.Delete(15);
		bSearch = tree.Search(15);
		traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(!bDelete);
		assert(!bSearch);
		assert(traverseResult.empty());

		tree.Insert(std::make_unique<int>(15));
		traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
		bDelete = tree.Delete(15);
		assert(bDelete);
		assert(traverseResult.size() == 1);
		assert(traverseResult[0] == 15);
	}
	// Test Insert GetRoot
	{
		BinarySearchTree<int> tree;

		int arr[10] = {10, 15, 5, 4, 19, 20, 17, 12, 7, 0};

		tree.Insert(std::make_unique<int>(arr[0]));
		tree.Insert(std::make_unique<int>(arr[1]));
		tree.Insert(std::make_unique<int>(arr[2]));
		tree.Insert(std::make_unique<int>(arr[3]));
		tree.Insert(std::make_unique<int>(arr[4]));
		tree.Insert(std::make_unique<int>(arr[5]));
		tree.Insert(std::make_unique<int>(arr[6]));
		tree.Insert(std::make_unique<int>(arr[7]));
		tree.Insert(std::make_unique<int>(arr[8]));

		std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
		assert(*test0->Data.get() == 10);
		assert(test0->Parent.lock().get() == nullptr);
		std::shared_ptr<TreeNode<int>> test1 = test0->Left;
		assert(*test1->Data.get() == 5);
		assert(*test1->Parent.lock()->Data.get() == 10);
		std::shared_ptr<TreeNode<int>> test2 = test1->Left;
		assert(*test2->Data.get() == 4);
		assert(*test2->Parent.lock()->Data.get() == 5);
		std::shared_ptr<TreeNode<int>> test3 = test1->Right;
		assert(*test3->Data.get() == 7);
		assert(*test3->Parent.lock()->Data.get() == 5);
		std::shared_ptr<TreeNode<int>> test4 = test0->Right;
		assert(*test4->Data.get() == 15);
		assert(*test4->Parent.lock()->Data.get() == 10);
		std::shared_ptr<TreeNode<int>> test5 = test4->Left;
		assert(*test5->Data.get() == 12);
		assert(*test5->Parent.lock()->Data.get() == 15);
		std::shared_ptr<TreeNode<int>> test6 = test4->Right;
		assert(*test6->Data.get() == 19);
		assert(*test6->Parent.lock()->Data.get() == 15);
		std::shared_ptr<TreeNode<int>> test7 = test6->Left;
		assert(*test7->Data.get() == 17);
		assert(*test7->Parent.lock()->Data.get() == 19);
		std::shared_ptr<TreeNode<int>> test8 = test6->Right;
		assert(*test8->Data.get() == 20);
		assert(*test8->Parent.lock()->Data.get() == 19);
	}
	// Test Search
	{
		BinarySearchTree<int> tree;

		int arr[10] = {10, 15, 5, 4, 19, 20, 17, 12, 7, 0};

		assert(!tree.Search(arr[0]));
		tree.Insert(std::make_unique<int>(arr[0]));
		assert(tree.Search(arr[0]));
		tree.Insert(std::make_unique<int>(arr[1]));
		assert(tree.Search(arr[1]));
		tree.Insert(std::make_unique<int>(arr[2]));
		assert(tree.Search(arr[2]));
		tree.Insert(std::make_unique<int>(arr[3]));
		assert(tree.Search(arr[3]));
		tree.Insert(std::make_unique<int>(arr[4]));
		assert(tree.Search(arr[4]));
		tree.Insert(std::make_unique<int>(arr[5]));
		assert(tree.Search(arr[5]));
		tree.Insert(std::make_unique<int>(arr[6]));
		assert(tree.Search(arr[6]));
		tree.Insert(std::make_unique<int>(arr[7]));
		assert(tree.Search(arr[7]));
		tree.Insert(std::make_unique<int>(arr[8]));
		assert(tree.Search(arr[8]));
		assert(!tree.Search(arr[9]));
	}

	// Test Delete
	{
		BinarySearchTree<int> tree;

		int arr[9] = {10, 15, 5, 4, 19, 20, 17, 12, 7};

		for (size_t i = 0 ; i < 9 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		//	End
		assert(!tree.Delete(9));    // 존재하지 않는 노드 삭제
		assert(tree.Delete(20));    // Right 노드 삭제
		assert(!tree.Search(20));    // 삭제 확인
		assert(tree.Delete(12));    // Left 노드 삭제
		assert(!tree.Search(12));    // 삭제 확인
		assert(!tree.Delete(11));    // 존재하지 않는 노드 삭제

		//	Middle
		assert(tree.Delete(19));    // Left만 있는 노드 삭제
		assert(!tree.Search(19));    // 삭제 확인
		assert(tree.Search(17));

		assert(tree.Delete(4));
		assert(tree.Delete(7));
		assert(tree.Delete(17));    // Left, Right 모두 없는 헤드 삭제
		assert(!tree.Search(17));    // 삭제 확인
		assert(!tree.Delete(17));    // 비어있는 상태에서 삭제

		// [5, 10, 15] -> TraverseInOrder
		for (size_t i = 0 ; i < 9 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}
		// [4, 5, 5, 7, 10, 10, 12, 15, 15, 17, 19, 20]
		tree.Delete(arr[0]); // [4, 5, 5, 7, 10, 12, 15, 15, 17, 19, 20]
		tree.Delete(arr[1]); // [4, 5, 5, 7, 10, 12, 15, 17, 19, 20]
		tree.Delete(arr[2]); // [4, 5, 7, 10, 12, 15, 17, 19, 20]
		tree.Delete(arr[3]); // [5, 7, 10, 12, 15, 17, 19, 20]
		tree.Delete(arr[4]); // [5, 7, 10, 12, 15, 17, 19]
		tree.Delete(arr[5]); // [5, 7, 10, 12, 15, 19]
		tree.Delete(arr[6]); // [5, 7, 10, 15, 19]
		tree.Delete(arr[7]);
		tree.Delete(arr[8]);
	}

	{
		BinarySearchTree<int> tree;

		tree.Insert(std::make_unique<int>(0));
		tree.Insert(std::make_unique<int>(1));
		tree.Insert(std::make_unique<int>(0));
		tree.Insert(std::make_unique<int>(0));
		tree.Insert(std::make_unique<int>(1));

		tree.Delete(0);
		tree.Delete(0);
		tree.Delete(1);
		tree.Delete(1);
		tree.Delete(0);

		tree.TraverseInOrder(tree.GetRootNode().lock());
	}

	{
		BinarySearchTree<int> tree;

		int arr[5] = {5, 3, 8, 6, 7};

		// 트리 입력
		for (size_t i = 0 ; i < 5 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		tree.Delete(5);
		tree.TraverseInOrder(tree.GetRootNode().lock());
	}

	// A - R - B
	{
		BinarySearchTree<int> tree;

		int arr[3] = {5, 3, 8};

		// 트리 입력
		for (size_t i = 0 ; i < 3 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 3 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// C - A - R - B
	{
		BinarySearchTree<int> tree;

		int arr[4] = {5, 3, 2, 8};

		// 트리 입력
		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// A - C - R - B
	{
		BinarySearchTree<int> tree;

		int arr[4] = {5, 3, 4, 8};

		// 트리 입력
		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// C - A - D - R - B
	{
		BinarySearchTree<int> tree;

		int arr[5] = {5, 3, 8, 2, 4};

		// 트리 입력
		for (size_t i = 0 ; i < 5 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 5 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// C - A - D - R - E - B
	{
		BinarySearchTree<int> tree;

		int arr[6] = {5, 3, 8, 2, 4, 6};

		// 트리 입력
		for (size_t i = 0 ; i < 6 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 6 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// C - A - D - R - E - B - F
	{
		BinarySearchTree<int> tree;

		int arr[7] = {5, 3, 8, 2, 4, 6, 10};

		// 트리 입력
		for (size_t i = 0 ; i < 7 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 7 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// A - R - C - B
	{
		BinarySearchTree<int> tree;

		int arr[4] = {5, 3, 8, 6};

		// 트리 입력
		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// A - R - C - B
	{
		BinarySearchTree<int> tree;

		int arr[4] = {5, 3, 8, 9};

		// 트리 입력
		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		for (size_t i = 0 ; i < 4 ; i++)
		{
			tree.Delete(arr[i]);
		}
		assert(tree.TraverseInOrder(tree.GetRootNode().lock()).size() == 0);
	}

	// Test Traverse
	{
		BinarySearchTree<int> tree;

		int arr[9] = {10, 15, 5, 4, 19, 20, 17, 12, 7};
		int arr_chk[9] = {4, 5, 7, 10, 12, 15, 17, 19, 20};

		// 빈 트리
		std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v1.size() == 0);
		assert(v1.empty());

		tree.Insert(std::make_unique<int>(arr[0]));
		// 헤드만 있는 트리
		std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v2.size() == 1);
		assert(v2[0] == arr[0]);

		// empty 포인터
		std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
		assert(v3.size() == 0);
		assert(v3.empty());

		// 트리 입력
		for (size_t i = 1 ; i < 9 ; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}
		// [4, 5, 7, 10, 12, 15, 17, 19, 20]

		// 헤드 노드 입력
		std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v4.size() == 9);
		assert(v4[0] == arr_chk[0]);
		assert(v4[1] == arr_chk[1]);
		assert(v4[2] == arr_chk[2]);
		assert(v4[3] == arr_chk[3]);
		assert(v4[4] == arr_chk[4]);
		assert(v4[5] == arr_chk[5]);
		assert(v4[6] == arr_chk[6]);
		assert(v4[7] == arr_chk[7]);
		assert(v4[8] == arr_chk[8]);

		// 중간 노드 입력
		std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
		assert(v5.size() == 3);
		assert(v5[0] == arr_chk[6]);
		assert(v5[1] == arr_chk[7]);
		assert(v5[2] == arr_chk[8]);

		// 말단 노드 입력
		std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
		assert(v6.size() == 1);
		assert(v6[0] == arr_chk[4]);

		// 노드 삭제
		for (size_t i = 0 ; i < 8 ; i++)
		{
			tree.Delete(arr[i]);
		}
		// arr [10, 15, 5, 4, 19, 20, 17, 12, 7]

		// [4, 5, 7, 12, 15, 17, 19, 20]
		// [4, 5, 7, 12, 17, 19, 20]
		// [4, 7, 12, 17, 19, 20]
		// [7, 12, 17, 19, 20]
		// [7, 12, 17]
		// [4, 5, 7, 12, 17, 19, 20]

		// 7만 남기고 모두 삭제된 트리
		std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v7.size() == 1);
		assert(v7[0] == arr[8]);

		// 노드가 모두 삭제된 트리
		tree.Delete(arr[8]);
		std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v8.size() == 0);
		assert(v8.empty());
	}
}