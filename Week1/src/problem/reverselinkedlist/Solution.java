// https://leetcode.com/problems/reverse-linked-list/
package problem.reverselinkedlist;

import java.util.ArrayList;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode head = new ListNode();
//        ListNode node1 = new ListNode(2);
//        ListNode node2 = new ListNode(3);
//        head.next = node1;
//        node1.next = node2;
        System.out.println(solution.reverseList(head));
    }
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ArrayList<ListNode> list = new ArrayList<>();

        ListNode tmp = head;
        while (tmp != null) {
            list.add(0, tmp);
            tmp = tmp.next;
        }

        for (int i = 0; i < list.size(); i++) {
            if (i == list.size() - 1) {
                list.get(i).next = null;
            } else {
                list.get(i).next = list.get(i + 1);
            }
        }

        return list.get(0);
    }
}
