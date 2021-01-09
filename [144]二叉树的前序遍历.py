# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        def dp(ans: List[int], root: TreeNode):
            if root:
                ans.append(root.val)
                dp(ans, root.left)
                dp(ans, root.right)
        
        ans = list()
        dp(ans, root)
        return ans
