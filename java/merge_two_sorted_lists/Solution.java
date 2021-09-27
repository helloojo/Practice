package merge_two_sorted_lists;

class ListNode {
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

class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode head = null;
		if (l1 == null && l2 == null) {
			return head;
		} else if (l1 != null && l2 == null) {
			return l1;
		} else if (l1 == null) {
			return l2;
		}
		ListNode cur = null;
		if (l1.val < l2.val) {
			head = cur = l1;
			l1 = l1.next;
		} else {
			head = cur = l2;
			l2 = l2.next;
		}
		while (l1 != null && l2 != null) {
			if (l1.val < l2.val) {
				cur = cur.next = l1;
				l1 = l1.next;
			} else {
				cur = cur.next = l2;
				l2 = l2.next;
			}
		}
		cur.next = l1 != null ? l1 : l2;
		return head;
	}
}
