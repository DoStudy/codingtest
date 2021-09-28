package algorithm.queue;

public class Queue {
    private final int size;
    private final int[] queue;
    private int last = -1;

    public Queue(int size) {
        this.size = size;
        this.queue = new int[size];
    }

    public void get() {
        if (!isEmpty()) {
            for (int i=1; i<=last; i++) {
                queue[i-1] = queue[i];
            }
            queue[last--] = 0;
        }
    }

    public void push(int value) {
        if (!isFull()) {
            queue[++last] = value;
        }
    }

    public int front() {
        if (!isEmpty()) {
            return queue[0];
        }
        throw new IndexOutOfBoundsException();
    }

    public int rear() {
        if (!isEmpty()) {
            return queue[last];
        }
        throw new IndexOutOfBoundsException();
    }

    public boolean isEmpty() { return last == -1; }

    public boolean isFull() { return last == size-1; }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (int val : queue) {
            str.append(val).append(" ");
        }
        return str.toString();
    }
}
