//
// Created by 남기륭 on 2021/09/26.
//

#pragma once

#include <memory>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T data);

	virtual ~Node() = default;

	T GetData() const;

	shared_ptr<Node<T>> GetNext() const;

	void SetNext(shared_ptr<Node<T>> next);

private:
	T mData;
	shared_ptr<Node<T>> mNext;
};

template<typename T>
Node<T>::Node(T data) : mData(data), mNext(nullptr)
{
}

template<typename T>
T Node<T>::GetData() const
{
	return *(mData.get());
}

template<typename T>
shared_ptr<Node<T>> Node<T>::GetNext() const
{
	return mNext;
}

template<typename T>
void Node<T>::SetNext(shared_ptr<Node<T>> next)
{
	mNext = next;
}
