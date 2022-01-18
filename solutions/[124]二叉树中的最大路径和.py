# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def helper(root):
            if root is None:
                return 0, -float('inf')
            
            l_length, l_ans = helper(root.left)
            r_length, r_ans = helper(root.right)

            return (max(0, l_length, r_length) + root.val,
                max(l_ans, r_ans, max(0, l_length) + max(0, r_length) + root.val))
        return helper(root)[1]
