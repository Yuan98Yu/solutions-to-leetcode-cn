# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        mid = self.get_mid_p(head)
        l1, l2 = head, mid.next
        mid.next = None

        l1 = self.sortList(l1)
        l2 = self.sortList(l2)
        return self.merge(l1, l2)

    
    def get_mid_p(self, head):
        if head is None or head.next is None:
            return head

        dummy = ListNode(0, head)
        slow, fast = dummy, dummy
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow
    
    def merge(self, l1, l2):
        dummy = ListNode()
        p = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        for l in [l1, l2]:
            while l:
                p.next = l
                l = l.next
                p = p.next
        return dummy.next
