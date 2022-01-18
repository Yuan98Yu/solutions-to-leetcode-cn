# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def helper(l, r):
            if l > r:
                return None
            p_root = (l+r) // 2

            return TreeNode(
                nums[p_root],
                helper(l, p_root-1),
                helper(p_root+1, r)
            )
        return helper(0, len(nums)-1)