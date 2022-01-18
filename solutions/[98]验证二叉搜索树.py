# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def helper(root):
            if root is None:
                return True, None, None
            min_val = root.val
            max_val = root.val
            l_is_valid, l_min_val, l_max_val = helper(root.left)
            r_is_valid, r_min_val, r_max_val = helper(root.right)
            is_valid = l_is_valid and r_is_valid
            if l_max_val is not None:
                is_valid = is_valid and root.val > l_max_val
                min_val = l_min_val
            if is_valid and r_max_val is not None:
                is_valid = is_valid and root.val < r_min_val
                max_val = r_max_val
            
            return is_valid, min_val, max_val
        return helper(root)[0]
