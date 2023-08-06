package linked_list_cycle;

class Solution2 {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode cur = head;
        ListNode next = head.next;
        while (cur != next && next != null && next.next != null) {
            cur = cur.next;
            next = next.next.next;
        }
        return cur == next;
    }
}