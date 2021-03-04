# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # search for middle node and divide List into l1, l2
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        middle = slow
        l1 = head
        l2 = middle.next
        middle.next = None

        # reverse from middle to end
        prev = None
        cur = middle
        while prev:
            tmp_cur = cur.next
            cur.next = prev
            prev = cur
            cur = tmp_cur

        # merge l1, l2
        while l2:
            l1_tmp, l2_tmp = l1.next, l2.next

            l1.next = l2
            l1 = l1_tmp
            l2.next = l1
            l2 = l2_tmp
