/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode slow = head, fast = head;
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode newHead = slow.next;
        slow.next = null;
        head = sortList(head);
        newHead = sortList(newHead);
        return merge(head, newHead);
    }
    
    public static ListNode merge(ListNode l1, ListNode l2){
        if(l1 == null) return l2;
	    if(l2 == null) return l1;
	    ListNode dummy = new ListNode(-1);
	    ListNode helper = dummy;
	    while(l1 != null && l2 != null){
	        if(l1.val < l2.val){
	            helper.next = l1;
	            l1 = l1.next;
	        }
	        else{
	            helper.next = l2;
	            l2 = l2.next;
	        }
	        helper = helper.next;
	    }
	    
	    if(l1 == null) helper.next = l2;
	    if(l2 == null) helper.next = l1;
	    return dummy.next;
    }
}