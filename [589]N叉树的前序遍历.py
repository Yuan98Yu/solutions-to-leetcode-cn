from typing import List


# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root: Node) -> List[int]:
        def dp(root, ans):
            if root:
                ans.append(root.val)

                for child in root.children:
                    dp(child, ans)
        
        ans = list()
        dp(root, ans)
        return ans
