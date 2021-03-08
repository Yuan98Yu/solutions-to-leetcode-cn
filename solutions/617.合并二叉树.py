#
# @lc app=leetcode.cn id=617 lang=python3
#
# [617] 合并二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        def dp(t1, t2):
            if t1 and t2:
                t1.val += t2.val
                t1.left = dp(t1.left, t2.left)
                t1.right = dp(t1.right, t2.right)
            elif not t1 and t2:
                t1 = TreeNode(t2.val)
                t1.left = t2.left
                t1.right = t2.right
                t1.left = dp(t1.left, None)
                t1.right = dp(t1.right, None)
            else:
                return t1
            
            return t1

        t1 = dp(t1, t2)
        return t1
        
# @lc code=end

