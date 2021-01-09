# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def exists(root, level, k):
            bits = 1 << (level-1)
            
        node = root
        level = 0
        while node:
            level += 1
            node = node.left
        
        low, high = 1 << level, (1 << (level+1)) - 1
        while low < high:
            mid = (low+high) / 2
            if 
    