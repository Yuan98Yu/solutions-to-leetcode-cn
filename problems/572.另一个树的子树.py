#
# @lc app=leetcode.cn id=572 lang=python3
#
# [572] 另一个树的子树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def is_same(s, t):
            if s is None and t is None:
                return True
            else:
                return s is not None and t is not None and s.val == t.val and is_same(
                    s.left, t.left) and is_same(s.right, t.right)
        if s is None and t is not None:
            return False
        return is_same(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

# @lc code=end
