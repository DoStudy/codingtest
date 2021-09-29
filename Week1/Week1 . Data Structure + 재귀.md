# Week1 . Data Structure + 재귀
#algorithm_study

## Data Structure 만들기 - Lab1
- Collection을 사용하지 않고 자료 구조 만들기 - 배열만 사용 가능
> 여기서 말하는 배열은 메모리 상의 연속적인 위치 되어 있어야 함!  

- 해당 동작에 맞게 함수 시그니쳐(자신이 사용하는 언어에 맞춰서)

-> Python : snake_case

-> Java : camelCase

-> C++ : PascalCase

- Data Structure에 맞춰서 추상화!
- 예시

``` java
public class Stack<T> {
	private Node topNode;
	...
	public void pop() {
		...
	}

	public void push(T data) {

	}
} 

public static void main() {
	Stack stack = new Stack();
	stack.push(5);
}
```

``` C++
template <typename T>
class Stack {
	public:
		public void push(T data) {

		}

	private:
		std::shared_ptr<Node<T>> mTop;
}
```

### 👉스택
1. pop 동작을 구현
-> 스택에서 가장 윗 데이터를 삭제

2. push 동작을 구현
-> 스택에서 가장 위에 데이터를 넣음

3. top 동작을 구현
-> 스택의 가장 위 데이터를 반환

4. empty 동작을 구현
-> 스택이 비어있는지 판단

—- 

### 👉큐
1. get 동작을 구현
-> 큐의 가장 앞에 있는 데이터를 제거 하는 것

2. push 동작을 구현
-> 큐에서 가장 뒤에 데이터를 추가 하는 것

3. front 동작을 구현
-> 큐에서 가장 앞에 있는 데이터를 반환

4. rear 동작을 구현
-> 큐에서 가장 뒤에 있는 데이터를 반환

—-

### 👉단일 연결 리스트
1. Insert 동작을 구현
-> 매개변수로 들어온 값을 LinkedList의 맨 마지막에 삽입

2. Delete 동작을 구현
-> 매개변수로 들어온 값과 같은 Node를 삭제(단, 처음으로 발견한 Node를 삭제)

3. PrintLinkedList 동작을 구현
-> 처음부터 끝까지 모든 원소를 출력
-> 예시 1 : [1, 2, 3] >> **1 -> 2 -> 3**
-> 예시 2 : [a, b, c] >> **a -> b -> c**

—-

## 재귀 문제 + 최적화! - Ass1
> 재귀의 문제점은? 해결 방법은?

[Fibonacci Number - LeetCode](https://leetcode.com/problems/fibonacci-number/)

[Reverse Linked List - LeetCode](https://leetcode.com/problems/reverse-linked-list/)

## 수정 History

> 20210929 : 
> 1. Node를 통해 구현하는 것 대신 ArrayList를 사용하는 예시 수정
> 2. Singly LinkedList의 구현 내용에 Node의 내용이 포함 되는 것을 수정