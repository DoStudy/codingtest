//
// Created by 남기륭 on 2021/09/26.
//

#ifndef LAB1_NODE_H
#define LAB1_NODE_H

#include <memory>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T data, const unique_ptr<T>& next);

	virtual ~Node();

	T getData() const;

	const unique_ptr<T>& getNext() const;

	bool operator==(const Node& rhs) const;

	// 복사 생성자
	// 대입 연산자
	// 등등

private:
	T data;
	unique_ptr<T> next;
};

template<typename T>
Node<T>::Node(T data, const unique_ptr<T>& next) : data(data), next(next)
{
}

template<typename T>
Node<T>::~Node()
{

}

template<typename T>
T Node<T>::getData() const
{
	return data;
}

template<typename T>
const unique_ptr<T>& Node<T>::getNext() const
{
	return next;
}

template<typename T>
bool Node<T>::operator==(const Node& rhs) const
{
	return false;
}

#endif //LAB1_NODE_H
