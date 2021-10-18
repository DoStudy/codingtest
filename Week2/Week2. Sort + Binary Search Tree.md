# Week2 . Sort + Binary Search Tree
#algorithm_study

## 1. 정렬 구현하기
- Collection에 있는 알고리즘을 사용하지 말 것! 배열에 적용하는 정렬 구현!
> 여기서 말하는 배열은 메모리 상의 연속적인 위치 되어 있어야 함!  

- 해당 동작에 맞게 함수 시그니쳐(자신이 사용하는 언어에 맞춰서)
-> Python : snake_case
-> Java : camelCase
-> C++ : PascalCase

### 1. 버블 정렬(Bubble Sort) - O(N^2)

### 2. 선택 정렬(Selection Sort) - O(N^2)

### 3. 삽입 정렬(Insertion Sort) - O(N^2)

### 4. 퀵 정렬(Quick Sort) - O(NLogN)

### 5. 병합 정렬(Merge Sort)- O(NLogN)

## 2. Data Structure - Binary Search Tree

https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%ED%83%90%EC%83%89_%ED%8A%B8%EB%A6%AC

1. TreeNode 구현
    - 1주차에서 만들어보았던 Doubly Linked List의 개념을 확장해 보기 위하여 TreeNode의 구현 명세 제공!
    
    - 트리 노드의 명세
    1. 클래스 형태로 만들 것!
    2. 값을 담고 있는 Data라는 변수
    3. 왼쪽 자식
    4. 오른쪽 자식
    5. 부모 

    - 생각해볼 것!
    1. 메모리 관련하여 문제가 될 수 있는 부분이 있는지
    2. 시간 복잡도가 예상하던 것과 일치 하는지    

``` java
public final class TreeNode  {

    public int data;
    public TreeNode left;
    public TreeNode right;
    public TreeNode parent;

    public TreeNode(int data) {

    }

    public TreeNode(TreeNode parent, int data) {

    }
}
```

``` c++
class TreeNode final 
{
    public:
        TreeNode(int data);
        TreeNode(TreeNode* parent, int data);
        
        int data;
        TreeNode* mLeft;
        TreeNode* mRight;
        TreeNode* mParent;
}
```

2. 삽입 구현 - Insert

> data를 집어 넣으면 맞는 위치에 삽입됩니다.

3. 탐색 구현

> data를 매개변수로 입력하면 해당하는 TreeNode가 반환 됩니다.

4. 삭제 구현

> data를 매개변수로 입력하면 해당하는 TreeNode가 삭제되고 bool / Boolean을 반환합니다.

5. 루트 노드 반환

> Tree의 RootNode를 반환합니다.

6. 값에 따라 오름 차순 출력

> 입력한 노드를 기준으로 오름차순으로 출력함

> 예시 이미지 첨부 - 처음으로 나온 BST 예시 -> 참고자료 아님

> https://www.geeksforgeeks.org/check-if-given-sorted-sub-sequence-exists-in-binary-search-tree/

> [1, 3, 4, 6, 7, 8, 10, 13, 14]

## 3. 문제!

- 이번주는 이미 구현만으로 많은 문제를 접할 수 있어 문제는 생략합니다!
