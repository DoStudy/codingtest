//
// Created by 남기륭 on 2021/09/26.
//

#pragma once

#include <iostream>
#include <memory>
#include "Node.h"

template<typename T>
class Node;

template<typename T>
class LinkedList
{
public:
	LinkedList() = default;

	virtual ~LinkedList() = default;

	bool Insert(T data);

	bool Delete(T data);

	void PrintLinkedList();

private:
	std::shared_ptr<Node<T>> mRoot;
};

template<typename T>
bool LinkedList<T>::Insert(T data)
{
	if (mRoot == nullptr)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
		mRoot = newNode;
		return true;
	}

	std::shared_ptr<Node<T>> currentNode = mRoot;

	while (currentNode->GetNext() != nullptr)
	{
		currentNode = currentNode->GetNext();
	}

	currentNode->SetNext(std::make_shared<Node<T>>(data));

	return true;
}

template<typename T>
bool LinkedList<T>::Delete(T data)
{
	if (mRoot == nullptr)
	{
		return false;
	}

	std::shared_ptr<Node<T>> currentNode = mRoot;
	shared_ptr<Node<T>> prevNode;

	while (currentNode != nullptr)
	{


		if (currentNode->GetData() == data)
		{
			if (currentNode == mRoot) // 처음에서 삭제
			{
				mRoot = currentNode->GetNext();
			}
			else
			{
				prevNode->SetNext(currentNode->GetNext());
			}

			currentNode.reset();

			return true;
		}

		prevNode = currentNode;
		currentNode = currentNode->GetNext();
	}

	return false;
}

template<typename T>
void LinkedList<T>::PrintLinkedList()
{
	shared_ptr<Node<T>> currentNode = mRoot;
	while (currentNode != nullptr)
	{
		if (currentNode->GetNext() != nullptr)
		{
			std::cout << currentNode->GetData() << "->";
		}
		else
		{
			std::cout << currentNode->GetData() << std::endl;
		}

		currentNode = currentNode->GetNext();
	}
}
