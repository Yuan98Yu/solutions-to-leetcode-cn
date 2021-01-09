from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = list()
        stack = [root]

        l2r_flag = True
        while stack:
            n, layer = len(stack), list()
            new_stack = list()
            for _ in range(n):
                node = stack.pop()
                if node is None:
                    continue

                layer.append(node.val)
                if l2r_flag:
                    new_stack.append(node.left)
                    new_stack.append(node.right)
                else:
                    new_stack.append(node.right)
                    new_stack.append(node.left)

            stack = new_stack
            l2r_flag = not l2r_flag
            if layer:
                ans.append(layer)

        return ans
