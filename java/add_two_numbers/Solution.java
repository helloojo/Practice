package add_two_numbers;

public class Solution {
    public static class ListNode {
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

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int l1val = 0;
        int l2val = 0;
        ListNode answer = null;
        ListNode answerPointer = null;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                l1val = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                l2val = l2.val;
                l2 = l2.next;
            }
            int sum = l2val + l1val + carry;
            l2val = 0;
            l1val = 0;
            carry = 0;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            if (answer == null) {
                answer = new ListNode(sum);
                answerPointer = answer;
            } else {
                answerPointer.next = new ListNode(sum);
                answerPointer = answerPointer.next;
            }
        }
        if (carry != 0) {
            answerPointer.next = new ListNode(carry);
        }
        return answer;
    }
}
