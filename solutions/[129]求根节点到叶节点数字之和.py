# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def dfs(root):
            res = list()
            if root is None:
                pass
            elif root.left is None and root.right is None:
                res = [(root.val, 1)]
            else:
                for tup in dfs(root.left) + dfs(root.right):
                    res.append(self.construct_num(root.val, tup))
            return res

        return sum([tup[0] for tup in dfs(root)])

    def construct_num(self, val, tup):
        digits, num_of_digits = tup[0], tup[1]
        return (val * 10 ** num_of_digits + digits, num_of_digits + 1)
