# Week1 . Data Structure + 재귀
#algorithm_study

## Data Structure 만들기
- Collection을 사용하지 않고 자료 구조 만들기 - 배열만 사용 가능
> 여기서 말하는 배열은 메모리 상의 연속적인 위치 되어 있어야 함!  

- 해당 동작에 맞게 함수 시그니쳐(자신이 사용하는 언어에 맞춰서)
-> Python : snake_case
-> Java : camelCase
-> C++ : PascalCase

- Data Structure에 맞춰서 추상화!
- 예시
``` java
public class Stack {
	private List<Long> stack = new ArrayList<>();
	...
	public void pop() {
		...
	}
} 

public static void main() {
	Stack stack = new Stack();
	stack.push(5);
}
```

### 스택
1. pop 동작을 구현
-> 스택에서 가장 윗 데이터를 삭제

2. push 동작을 구현
-> 스택에서 가장 위에 데이터를 넣음

3. top 동작을 구현
-> 스택의 가장 위 데이터를 반환

4. empty 동작을 구현
-> 스택이 비어있는지 판단

—- 

### 큐 + 시간이 남는다면 원형 큐
1. get 동작을 구현
-> 큐의 가장 앞에 있는 데이터를 제거 하는 것

2. push 동작을 구현
-> 큐에서 가장 뒤에 데이터를 추가 하는 것

3. front 동작을 구현
-> 큐에서 가장 앞에 있는 데이터를 반환

4. rear 동작을 구현
-> 큐에서 가장 뒤에 있는 데이터를 반환

—-

### 단일 연결 리스트
1. setNext 동작을 구현
-> 다음 노드를 지정함

2. getNext 동작을 구현
-> 다음 노드에 접근함

3. getData 동작을 구현
-> 데이터를 반환함

4. delete 동작을 구현
-> 해당 노드를 삭제함

—-

### 이중 연결 리스트
1. setNext 동작을 구현
-> 다음 노드를 지정함

2. setPrevious 동작을 구현
-> 이전 노드를 지정함

3. getNext 동작을 구현
-> 다음 노드에 접근함

4. getPrevious 동작을 구현
-> 이전 노드에 접근함

5. getData 동작을 구현
-> 데이터를 반환함

6. delete 동작을 구현
-> 해당 노드를 삭제함

## 재귀 문제 + 최적화!
> 재귀의 문제점은? 해결 방법은?

[Fibonacci Number - LeetCode](https://leetcode.com/problems/fibonacci-number/)

[Reverse Linked List - LeetCode](https://leetcode.com/problems/reverse-linked-list/)
