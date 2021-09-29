#include <iostream>
using namespace std;

template <typename DO>
struct Node {
	DO value;
	struct Node<DO>* prevNode = nullptr;
	struct Node<DO>* nextNode = nullptr;
};
template <typename DO>
class stack {
	Node<DO>* first = nullptr;
	Node<DO>* last = nullptr;
public:
	stack() {
		first = nullptr;
		last = nullptr;
	}
	void push(DO value) {
		Node<DO>* temp = new Node<DO>();
		temp->value = value;
		temp->prevNode = nullptr;
		temp->nextNode = nullptr;
		if (first == nullptr) {
			first = temp;
			last = temp;
		}
		else {
			last->nextNode = temp;
			temp->prevNode = last;
			last = temp;
		}
	}
	DO pop() {
		DO temp = last->value;
		last = last->prevNode;
		free(last->nextNode);
		return temp;
	}
	DO top() {
		return last->value;
	}
	bool isEmpty() {
		return last == nullptr && first == nullptr;
	}
};
template <typename DO>
class queue {
	Node<DO>* first = nullptr;
	Node<DO>* last = nullptr;
public:
	queue() {
		first = nullptr;
		last = nullptr;
	}
	void push(DO value) {
		Node<DO>* temp = new Node<DO>();
		temp->value = value;
		temp->prevNode = nullptr;
		temp->nextNode = nullptr;
		if (first == nullptr) {
			first = temp;
			last = temp;
		}
		else {
			last->nextNode = temp;
			temp->prevNode = last;
			temp->nextNode = first;
			first->prevNode = temp;
			last = temp;
		}
	}
	DO get() {
		DO temp = first->value;
		first = first->nextNode;
		free(first->prevNode);
		first->prevNode = last;
		return temp;
	}
	DO front() {
		return first->value;
	}
	DO frontPrev() {
		return first->prevNode->value;
	}
	DO rear() {
		return last->value;
	}
	DO rearNext() {
		return last->nextNode->value;
	}
};

template <typename DO>
class singleList {
	Node<DO>* first = nullptr;
	Node<DO>* last = nullptr;
public:
	int size = 0;
	singleList() {
		first = nullptr;
		last = nullptr;
	}

	void setNext(DO value) {
		Node<DO>* temp = new Node<DO>();
		temp->value = value;

		if (first == nullptr) {
			first = temp;
			last = temp;
		}
		else {
			last->nextNode = temp;
			temp->prevNode = last;
			last = temp;
		}
		size++;
	}

	Node<DO>* getNext(Node<DO>* InputNode) {
		return InputNode->nextNode;
	}

	DO* getData() {
		DO* temp = new DO[size];
		Node<DO>* startPoint = first;
		int index = 0;
		while (startPoint != nullptr) {
			temp[index] = startPoint->value;
			startPoint = startPoint->nextNode;
			index++;
		}
		return temp;
	}

	void deleteData(int index) {
		Node<DO>* startPoint = first;
		Node<DO>* prevPoint = nullptr;
		int nowIndex = 0;
		while (startPoint != nullptr) {
			if (nowIndex != index)
			{
				prevPoint = startPoint;
				startPoint = startPoint->nextNode;
				continue;
			}
			else {
				prevPoint->nextNode = startPoint->nextNode;
				free(startPoint);
			}
		}
	}
};

int main()
{
	stack<int> TestStack;
	TestStack.push(1);
	TestStack.push(2);
	TestStack.push(3);
	TestStack.push(4);
	TestStack.push(5);
	int returnValue = 0;
	returnValue = TestStack.pop();
	returnValue = TestStack.pop();
	returnValue = TestStack.pop();
	bool isEmpty = false;
	isEmpty = TestStack.isEmpty();

	queue<int> TestQueue;
	TestQueue.push(6);
	TestQueue.push(7);
	returnValue = TestQueue.rear();
	returnValue = TestQueue.rearNext();
	TestQueue.push(8);
	returnValue = TestQueue.rear();
	TestQueue.push(9);
	TestQueue.push(10);
	returnValue = TestQueue.get();
	returnValue = TestQueue.front();
	returnValue = TestQueue.frontPrev();

	singleList<int> TestSingleList;
	TestSingleList.setNext(1);
	TestSingleList.setNext(2);
	TestSingleList.setNext(3);
	TestSingleList.setNext(4);
	TestSingleList.setNext(5);
	int* returnValues = TestSingleList.getData();
	for (int i = 0; i < TestSingleList.size; i++) {
		printf("%d ", returnValues[i]);
	}
}