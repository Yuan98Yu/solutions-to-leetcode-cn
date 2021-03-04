#
# @lc app=leetcode.cn id=872 lang=python3
#
# [872] 叶子相似的树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        leaves1 = list()
        leaves2 = list()

        def dfs(root, leaves):
            if root is None:
                return
            elif root.left is None and root.right is None:
                leaves.append(root.val)
            else:
                dfs(root.left, leaves)
                dfs(root.right, leaves)

        dfs(root1, leaves1)
        dfs(root2, leaves2)

        return leaves1 == leaves2
# @lc code=end

