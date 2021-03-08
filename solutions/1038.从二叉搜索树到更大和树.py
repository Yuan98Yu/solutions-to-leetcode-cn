#
# @lc app=leetcode.cn id=1038 lang=python3
#
# [1038] 从二叉搜索树到更大和树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(root, val):
            if root is None:
                return val
            
            larger_sum = dfs(root.right, val)
            root.val += larger_sum
            return dfs(root.left, root.val)

        dfs(root, 0)
        return root

# @lc code=end

