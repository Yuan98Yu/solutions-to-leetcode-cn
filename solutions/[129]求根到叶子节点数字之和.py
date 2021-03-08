# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def dp(root, num):
            if root is None:
                return 0
            if root.left is None and root.right is None:
                return num*10 + root.val

            return dp(root.left, num*10+root.val) + dp(root.right, num*10+root.val)
        
        return dp(root, 0)