#
# @lc app=leetcode.cn id=538 lang=python3
#
# [538] 把二叉搜索树转换为累加树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def dfs(root, sum):
            if root is None:
                return sum

            root.val += dfs(root.right, sum)
            return dfs(root.left, root.val)
        
        dfs(root, 0)
        return root

# @lc code=end

