package algorithm.stack;

public class StackExec {
    public static void main(String[] args) {
        Stack stack = new Stack(10);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);
        stack.push(70);
        stack.push(80);
        stack.push(90);
        stack.push(100);
        stack.push(110);

        System.out.println(stack.isFull());
        System.out.println(stack.isEmpty());
        System.out.println(stack);
        stack.pop();
        System.out.println(stack);
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        System.out.println(stack);
        System.out.println(stack.isFull());
        System.out.println(stack.isEmpty());
    }
}
