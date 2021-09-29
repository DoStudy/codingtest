//
// Created by 남기륭 on 2021/09/26.
//

#pragma once

#include "Node.h"

template<typename T>
class Queue
{
public:
	Queue();

	void Pop();

	bool Push(T data);

	T Front();

	T Rear();

private:
	shared_ptr<Node<T>> mFrontNode;
	shared_ptr<Node<T>> mRearNode;
};


template<typename T>
bool Queue<T>::Push(T data)
{
	shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
	if (mFrontNode == nullptr)
	{
		mFrontNode = newNode;
		mRearNode = newNode;

		return true;
	}

	if (mFrontNode == mRearNode)
	{
		mFrontNode->SetNext(newNode);
		mRearNode = newNode;
		return true;
	}

	mRearNode->SetNext(newNode);
	mRearNode = newNode;

	return true;
}

template<typename T>
void Queue<T>::Pop()
{
	shared_ptr<Node<T>> previousFrontNode = mFrontNode;
	if (previousFrontNode->GetNext() != nullptr)
	{
		mFrontNode = previousFrontNode->GetNext();
	} else {
		mFrontNode.reset();
		mRearNode.reset();
	}

	previousFrontNode.reset();
}

template<typename T>
T Queue<T>::Front()
{
	return mFrontNode->GetData();
}

template<typename T>
T Queue<T>::Rear()
{
	if (mRearNode == nullptr)
	{
		return INT_MIN;
	}
	return mRearNode->GetData();
}

template<typename T>
Queue<T>::Queue()
{
	mFrontNode = 0;
}



