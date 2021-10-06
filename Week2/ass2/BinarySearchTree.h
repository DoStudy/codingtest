#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "TreeNode.h"

namespace ass2
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);

		bool Search(const T& data);

		bool Delete(const T& data);

		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		bool DeleteNode(std::shared_ptr<TreeNode<T>> startNode, const T& data);

		std::shared_ptr<TreeNode<T>> FindSuccessor(std::shared_ptr<TreeNode<T>> startNode);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

		static void TraverseInOrderRecursive(std::vector<T>& traverseInOrderVector, const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(std::move(data));
			mRoot = newNode;
		}
		else
		{
			// 현재 노드에 Root 노드 대입
			std::shared_ptr<TreeNode<T>> currentNode = mRoot;

			while (currentNode != nullptr)
			{
				if (*data <= *(currentNode.get()->Data))
				{
					if (currentNode.get()->Left == nullptr)
					{
						currentNode.get()->Left = std::make_shared<TreeNode<T>>(currentNode, std::move(data));
						return;
					}
					currentNode = currentNode.get()->Left;
				}
				else
				{
					if (currentNode.get()->Right == nullptr)
					{
						currentNode.get()->Right = std::make_shared<TreeNode<T>>(currentNode, std::move(data));
						return;
					}
					currentNode = currentNode.get()->Right;
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		// 현재 노드에 Root 노드 대입
		std::shared_ptr<TreeNode<T>> currentNode = mRoot;

		while (currentNode != nullptr)
		{
			T currentData = *(currentNode.get()->Data.get());
			if (data == currentData)
			{
				return true;
			}
			else if (data <= currentData)
			{
				currentNode = currentNode.get()->Left;
			}
			else
			{
				currentNode = currentNode.get()->Right;
			}
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return DeleteNode(mRoot, data);
	}

	template<typename T>
	bool BinarySearchTree<T>::DeleteNode(std::shared_ptr<TreeNode<T>> startNode, const T& data)
	{
		// 현재 노드에 Root 노드 대입
		std::shared_ptr<TreeNode<T>> currentNode = startNode;

		while (currentNode != nullptr)
		{
			T currentData = *(currentNode.get()->Data.get());

			if (data == currentData)
			{
				// 1. 삭제 노드의 자식이 없음
				if (currentNode.get()->Left == nullptr && currentNode.get()->Right == nullptr)
				{
					std::shared_ptr<TreeNode<T>> parentNode = currentNode.get()->Parent.lock();

					if (currentNode != mRoot)
					{
						if (parentNode.get()->Left == currentNode)
						{
							parentNode.get()->Left = nullptr;
						}
						else
						{
							parentNode.get()->Right = nullptr;
						}
					}
					else
					{
						mRoot.reset();
					}

					currentNode.reset();
					return true;
				}
				else if (currentNode.get()->Left != nullptr && currentNode.get()->Right != nullptr)
				{
					// 1. 대체할 노드 찾아서 반환
					std::shared_ptr<TreeNode<T>> successor = FindSuccessor(currentNode.get()->Right);

					// 2. 대체 노드가 삭제 노드의 오른쪽 자식인지 아닌지
					T successorData = *(successor.get()->Data.get());
					currentNode.get()->Data.reset(new T(successorData));

					DeleteNode(successor, successorData);

					return true;
				}
				else // 2. 삭제 노드의 자식이 하나
				{
					std::shared_ptr<TreeNode<T>> childNode;

					if (currentNode != mRoot)
					{
						std::shared_ptr<TreeNode<T>> parentNode = currentNode.get()->Parent.lock();

						// Left Node를 삭제 노드 위치로
						if (currentNode.get()->Left != nullptr)
						{
							childNode = currentNode.get()->Left;
							childNode.get()->Parent = currentNode.get()->Parent;
						}
						else // Right Node를 삭제 노드 위치로
						{
							childNode = currentNode.get()->Right;
							childNode.get()->Parent = currentNode.get()->Parent;
						}

						// parent node에 연결
						if (parentNode.get()->Left == currentNode)
						{
							parentNode->Left = childNode;
						}
						else
						{
							parentNode->Right = childNode;
						}
					}
					else // 삭제 노드가 mRoot이면
					{
						if (currentNode.get()->Left != nullptr)
						{
							mRoot = currentNode.get()->Left;
						}
						else
						{
							mRoot = currentNode.get()->Right;
						}

						mRoot.get()->Parent.reset();
					}

					currentNode.reset();
					return true;
				}
			}
			else if (data < currentData)
			{
				currentNode = currentNode.get()->Left;
			}
			else
			{
				currentNode = currentNode.get()->Right;
			}
		}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> traverseVector;

		if (startNode == nullptr)
		{
			return traverseVector;
		}

		TraverseInOrderRecursive(traverseVector, startNode);

		return std::vector<T>(traverseVector);
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::FindSuccessor(std::shared_ptr<TreeNode<T>> startNode)
	{
		std::shared_ptr<TreeNode<T>> currentNode = startNode;
		while (currentNode != nullptr)
		{
			if (currentNode.get()->Left == nullptr)
			{
				return currentNode;
			}
			currentNode = currentNode.get()->Left;
		}

		return std::make_shared<TreeNode<T>>(nullptr);
	}

	template<typename T>
	void BinarySearchTree<T>::TraverseInOrderRecursive(std::vector<T>& traverseInOrderVector, const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode != nullptr)
		{
			TraverseInOrderRecursive(traverseInOrderVector, startNode.get()->Left);
			traverseInOrderVector.push_back(*(startNode.get()->Data.get()));
			TraverseInOrderRecursive(traverseInOrderVector, startNode.get()->Right);
		}
	}


}