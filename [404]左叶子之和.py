# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.dp(root, False)

    def dp(self, root, is_left):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return root.val if is_left else 0
        else:
            return self.dp(root.left, True) + self.dp(root.right, False)
