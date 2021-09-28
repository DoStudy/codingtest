public class MyLimitedStack<T> {
    private T[] node;
    public int pointer = 0;

    public MyLimitedStack(int stackSize) {
        node = (T[]) new Object[stackSize];
    }

    private void checkEmpty() {
        if (this.pointer == 0 && this.node[pointer] == null) System.exit(-1);
    }

    private boolean isFull() {
        return this.pointer == this.node.length;
    }

    public T pop() {
        T top = this.top();
        pointer -= 1;
        this.node[pointer] = null;

        return top;
    }

    public void push(T t) {
        if(!this.isFull()) {
            this.node[pointer] = t;
            this.pointer += 1;
        } else System.out.println("Stack is full!");
    }

    public T top() {
        this.checkEmpty();

        return node[this.pointer - 1];
    }

    public boolean empty() {
        return (this.pointer == 0 && this.node[pointer] == null);
    }

    public String toString() {
        this.checkEmpty();

        String output = "";
        for (T t : this.node) {
            output += "[" + t + "]";
        }

        return output;
    }
}

class MyLimitedStackTest {
    public static void main(String[] args) {
        MyLimitedStack<Integer> myStack = new MyLimitedStack<Integer>(5);

        System.out.println(myStack.empty()); // true
        myStack.push(1);
        System.out.println(myStack.top()); // 1
        myStack.push(2);
        myStack.push(3);
        System.out.println(myStack.pop()); // 3 and 3 is removed
        System.out.println(myStack.top()); // 2
        myStack.push(4);
        System.out.println(myStack.top()); // 4
        myStack.push(5);
        System.out.println(myStack.top()); // 5
        myStack.push(6);
        System.out.println(myStack.top()); // 6
        System.out.println(myStack.empty()); // false
        myStack.push(10); // full

        System.out.println(myStack.toString());
    }
}