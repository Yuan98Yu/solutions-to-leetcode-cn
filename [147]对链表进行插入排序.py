# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None:
            return head

        dummy = ListNode(float('-inf'))
        dummy.next = head
        last_sorted = head
        p = head.next

        while p is not None:
            if last_sorted.val <= p.val:
                last_sorted = last_sorted.next
            else:
                prev = dummy
                while prev.next.val <= p.val:
                    prev = prev.next
                last_sorted.next = p.next
                p.next = prev.next
                prev.next = p
            p = last_sorted.next
        
        return dummy.next
