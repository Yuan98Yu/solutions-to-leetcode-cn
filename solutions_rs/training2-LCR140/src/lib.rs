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
    pub fn training_plan(head: Option<Box<ListNode>>, cnt: i32) -> Option<Box<ListNode>> {
        let mut fast_node = &head;
        let mut slow_node = &head;
        for _ in 0..cnt {
            fast_node = &fast_node.as_ref().unwrap().next;
        }

        while fast_node.is_some() {
            fast_node = &fast_node.as_ref().unwrap().next;
            slow_node = &slow_node.as_ref().unwrap().next;
        }

        slow_node.to_owned()
    }
}