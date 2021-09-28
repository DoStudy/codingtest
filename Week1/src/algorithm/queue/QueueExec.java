package algorithm.queue;

public class QueueExec {
    public static void main(String[] args) {
        Queue queue = new Queue(5);
        queue.push(10);
        queue.push(20);
        System.out.println(queue.isEmpty());
        System.out.println(queue.isFull());
        System.out.println(queue.front());
        System.out.println(queue.rear());
        queue.get();
        System.out.println(queue);
    }
}
