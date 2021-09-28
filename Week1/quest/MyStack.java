import java.util.ArrayList;

public class MyStack<T> {
    private ArrayList<T> node = new ArrayList<T>();

    private void checkEmpty() {
        if (node.size() <= 0) System.exit(-1);
    }

    public T pop() {
        T top = this.top();
        node.remove(node.size() - 1);
        return top;
    }

    public void push(T t) {
        node.add(t);
    }

    public T top() {
        this.checkEmpty();

        return node.get(node.size() - 1);
    }

    public boolean empty() { // isEmpty
        return node.size() <= 0;
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

class MyStackTest {
    public static void main(String[] args) {
        MyStack<Integer> myStack = new MyStack<Integer>();

        myStack.push(1);
        myStack.push(2);
        myStack.push(4);
        System.out.println(myStack.top());
        myStack.push(11);
        System.out.println(myStack.pop());
        myStack.push(10);
        System.out.printf("stack is empty? = %s%n",  myStack.empty());
        System.out.println(myStack.pop());
        System.out.println(myStack.pop());
        System.out.println(myStack.pop());
        System.out.println(myStack.pop());
        System.out.printf("stack is empty? = %s%n",  myStack.empty());
        myStack.push(7);
        myStack.push(7);

        System.out.println(myStack.toString());
    }
}