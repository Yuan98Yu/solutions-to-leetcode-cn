#
# @lc app=leetcode.cn id=337 lang=python3
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        memo = dict()
        memo[(None, True)] = 0
        memo[(None, False)] = 0
        def dfs(root, flag):
            val = memo.get((root, flag), None)
            if val is not None:
                return val

            val = dfs(root.left, False) + dfs(root.right, False)
            if not flag:
                val = max(val,
                    root.val + dfs(root.left, True) + dfs(root.right, True))
            memo[(root, flag)] = val
            return val
        
        return dfs(root, False)

# @lc code=end

