//
// Created by 남기륭 on 2021/09/26.
//

#pragma once

#include <memory>

template<typename T>
class Stack
{
public:
	void Pop();

	bool Push(T data);

	T Top();

	bool IsEmpty();

private:
	shared_ptr <Node<T>> mTopNode;
};

template<typename T>
void Stack<T>::Pop()
{
	std::shared_ptr<Node<T>>
	previousTopNode = mTopNode;
	mTopNode = mTopNode->GetNext();

	previousTopNode.reset();
}

template<typename T>
bool Stack<T>::Push(T data)
{
	if (mTopNode == nullptr)
	{
		mTopNode = make_shared < Node < T >> (data);
		return true;
	}

	shared_ptr <Node<T>> newNode = make_shared < Node < T >> (data);
	newNode->SetNext(mTopNode);
	mTopNode = newNode;

	return true;
}

template<typename T>
T Stack<T>::Top()
{
	return mTopNode->GetData();
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return mTopNode == nullptr;
}