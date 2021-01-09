# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        rec_head = head.next.next
        new_head = head.next
        new_head.next = head
        head.next = self.swapPairs(rec_head)
        
        return new_head
