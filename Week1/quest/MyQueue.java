import java.util.ArrayList;

public class MyQueue<T> {
    private ArrayList<T> node = new ArrayList<T>();

    private void checkEmpty() {
        if (this.node.size() <= 0) System.exit(-1);
    }

    public T get() {
        T front = this.front();
        this.node.remove(0);

        return front;
    }

    public void push(T data) {
        this.node.add(data);
    }

    public T front() {
        this.checkEmpty();

        return node.get(0);
    }

    public T rear() {
        return this.node.get(node.size() - 1);
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

class MyQueueTest {
    public static void main(String[] args) {
        MyQueue<Integer> myQueue = new MyQueue<Integer>();
        System.out.println();
        myQueue.push(1);
        System.out.println(myQueue.front()); // 1
        System.out.println(myQueue.rear()); // 1
        myQueue.push(2);
        myQueue.push(3);
        System.out.println(myQueue.get()); // 1
        System.out.println(myQueue.front()); // 2
        System.out.println(myQueue.rear()); // 3
        myQueue.push(5);
        myQueue.push(6);
        System.out.println(myQueue.get()); // 2

        System.out.println(myQueue.toString());
    }
}
