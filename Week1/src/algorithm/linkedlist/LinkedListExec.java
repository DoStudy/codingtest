package algorithm.linkedlist;

public class LinkedListExec {
    public static void main(String[] args) {
        LinkedList root = new LinkedList(1);
        LinkedList linkedList2 = new LinkedList(2);
        LinkedList linkedList3 = new LinkedList(3);
        root.setNext(linkedList2);
        linkedList2.setNext(linkedList3);
        root.delete();
        root = linkedList2;

        System.out.println(root);
    }
}
