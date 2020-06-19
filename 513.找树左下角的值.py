#
# @lc app=leetcode.cn id=513 lang=python3
#
# [513] 找树左下角的值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        self.ans = [-1, -1]

        def dfs(root, depth):
            if root is None:
                return
            if root.left is None and root.right is None:
                if depth > self.ans[0]:
                    self.ans = [depth, root.val]
            else:
                dfs(root.left, depth + 1)
                dfs(root.right, depth + 1)
        
        dfs(root, 0)
        return self.ans[1]

# @lc code=end

