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
      next: None,
      val
    }
  }
}
impl Solution {
    pub fn trainning_plan(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut pre_node: Option<Box<ListNode>> = None;
        let mut cur_node = head;
        while let Some(mut next_p) = cur_node {
            cur_node = next_p.next;
            next_p.next = pre_node;
            pre_node = Some(next_p);
        }
        pre_node
    }
}