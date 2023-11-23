struct Solution;
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
impl Solution {
    pub fn trainning_plan(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut current = &mut dummy;

        let mut l1 = l1;
        let mut l2 = l2;

        while let (Some(n1), Some(n2)) = (l1, l2) {
            let cur_p = current.as_mut().unwrap();
            if n1.val <= n2.val {
                cur_p.next = Some(n1);
                l1 = cur_p.as_mut().next;
            } else {
                cur_p.next = l2.take();
                l2 = n2.next.take();
            }
            current = &mut current.as_mut().unwrap().next;
        }

        current.as_mut().unwrap().next = if l1.is_some() { l1 } else { l2 };

        dummy.unwrap().next
    }
}
