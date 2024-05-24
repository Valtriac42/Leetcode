import java.util.Scanner;

public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for the number of elements in the linked list
        System.out.println("Enter the number of elements in the linked list:");
        int n = scanner.nextInt();

        // Taking input for the elements of the linked list
        System.out.println("Enter the elements of the linked list:");
        ListNode head = null;
        ListNode tail = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            ListNode newNode = new ListNode(val);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = tail.next;
            }
        }

        Solution solution = new Solution();
        boolean hasCycle = solution.hasCycle(head);
        System.out.println("Does the linked list have a cycle? " + hasCycle);

        scanner.close();
    }

    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
}
