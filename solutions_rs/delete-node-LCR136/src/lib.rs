struct Solution;
// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: Option::<Box<ListNode>>::None,
      val
    }
  }
}
impl Solution {
    pub fn delete_node(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
      let mut dummy = Some(Box::new(ListNode::new(0)));
      dummy.as_mut().unwrap().next = head;
      let mut cur = &mut dummy;
      while let Some(next_node) = &mut cur.as_mut().unwrap().next {
        if next_node.val == val {
          cur.as_mut().unwrap().next = next_node.next.take();
          break;
        }
        cur = &mut cur.as_mut().unwrap().next;
      }
      dummy.unwrap().next
    }
}