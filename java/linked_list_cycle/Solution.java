package linked_list_cycle;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }
        final Set<ListNode> nodeSet = new HashSet<>();
        ListNode cur = head;
        while (cur.next != null && !nodeSet.contains(cur)) {
            nodeSet.add(cur);
            cur = cur.next;
        }
        return cur.next != null;
    }
}