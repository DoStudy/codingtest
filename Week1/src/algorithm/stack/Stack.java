package algorithm.stack;

public class Stack {
    private final int size;
    private final int[] stack;
    private int top = -1;

    public Stack(int size) {
        this.size = size;
        this.stack = new int[size];
    }

    public void pop() {
        if (!isEmpty()) {
            stack[top--] = 0;
        }
    }

    public void push(int value) {
        if (!isFull()) {
            stack[++top] = value;
        }
    }

    public int top() {
        return stack[top];
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    public boolean isFull() {
        return (top == size - 1);
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (int val : stack) {
            str.append(val).append(" ");
        }
        return str.toString();
    }
}
