# Definition for a binary tree node.
from typing import List


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        val2p_in = dict()
        for i, val in enumerate(inorder):
            val2p_in[val] = i
        def build_tree(p_pre, l_in, r_in):
            if l_in > r_in:
                return None
            root_val = preorder[p_pre]

            p_root_in = val2p_in[root_val]
            root = TreeNode(root_val,
                            build_tree(p_pre+1, l_in, p_root_in-1),
                            build_tree(p_root_in-l_in+p_pre+1, p_root_in+1, r_in))
            return root
        
        return build_tree(0, 0, len(inorder)-1)
