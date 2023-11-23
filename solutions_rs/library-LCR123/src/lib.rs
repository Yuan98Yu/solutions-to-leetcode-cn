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
    pub fn reverse_book_list(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut cur = head;
        let mut res = vec![];
        while let Some(node) = cur {
            res.push(node.val);
            cur = node.next;
        }
        res.reverse();
        res
    }
}