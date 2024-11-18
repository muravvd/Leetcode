import java.util.List;

/*
public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
*/

public class Solution {

    public static ListNode createLinkedList(List<Integer> arr) {
        if (arr == null || arr.isEmpty())
            return null;
        ListNode head = new ListNode(arr.get(0));
        ListNode current = head;
        for (int i = 1; i < arr.size(); i++) {
            current.next = new ListNode(arr.get(i));
            current = current.next;
        }
        return head;
    }

    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public ListNode partition(ListNode head, int x) {   // 0ms 41mb
        ListNode left = new ListNode();
        ListNode right = new ListNode();
        ListNode start = left;
        ListNode cont = right;
        while (head != null) {
            if (head.val < x) {
                left.next = head;
                left = left.next;
            } else {
                right.next = head;
                right = right.next;
            }
            head = head.next;
        }
        right.next = null;
        left.next = cont.next;
        return start.next;
    }

    public static void main(String[] args) {
        List<Integer> arr = List.of(1, 4, 3, 2, 5, 2);
        ListNode list1 = createLinkedList(arr);
        printList(list1);
        Solution solution = new Solution();
        ListNode result = solution.partition(list1, 3);
        printList(result);
    }
}