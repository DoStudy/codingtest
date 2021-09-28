package algorithm.linkedlist;

public class LinkedList {
    private final int value;
    public LinkedList pre;
    private LinkedList next;

    public LinkedList(int value) {
        this.value = value;
    }

    public int getData() {
        return value;
    }

    public void setNext(LinkedList next) {
        next.pre = this;
        this.next = next;
    }

    public LinkedList getNext() {
        return next;
    }

    public void delete() {
        // 지금 노드가 맨 첫 번째 노드일 때 (좀 애매함..)
        if (pre == null && next != null) {
            next.pre = null;
        }
        // 지금 노드가 맨 마지막 노드일 때
        if (pre != null && next == null) {
            pre.next = null;
        }
        // 지금 노드가 중간 노드일 때
        if (pre != null && next != null) {
            pre.next = next;
            next.pre = pre;
        }
        pre = null;
        next = null;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append(value);
        LinkedList tmp = next;
        while (tmp != null) {
            str.append("->").append(tmp.value);
            tmp = tmp.next;
        }
        return str.toString();
    }
}
