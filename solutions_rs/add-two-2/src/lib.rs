// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut new_l = ListNode::new(0);
        let mut cur = &mut new_l;

        let (mut l1, mut l2) = (l1.as_ref(), l2.as_ref());
        let mut carry = 0;
        while let (Some(node1), Some(node2)) = (&l1, &l2) {
            let mut sum = carry + node1.val + node2.val;
            carry = sum / 10;
            sum = sum % 10;
            cur.next = Some(Box::new(ListNode::new(sum)));
            cur = cur.next.as_mut().unwrap();
            l1 = node1.next.as_ref();
            l2 = node2.next.as_ref();
        }

        cur.next = if l1.is_some() {
            l1.cloned()
        } else if l2.is_some() {
            l2.cloned()
        } else {
            None
        };

        while carry == 1 {
			if cur.next.is_none() {
				cur.next = Some(Box::new(ListNode::new(0)));
			}
            cur = cur.next.as_mut().unwrap();
            let mut sum = carry + cur.val;
            carry = sum / 10;
            sum = sum % 10;
            cur.val = sum;
        }

        new_l.next
    }
}
