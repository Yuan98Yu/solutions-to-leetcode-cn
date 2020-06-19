#
# @lc app=leetcode.cn id=990 lang=python3
#
# [990] 等式方程的可满足性
#

# @lc code=start
class DSU:
    def __init__(self, N):
        self.p = list(range(N))

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[yr] = xr


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = DSU(26)
        for equation in equations:
            if equation[1] == "=":
                index1 = ord(equation[0]) - ord("a")
                index2 = ord(equation[3]) - ord("a")
                uf.union(index1, index2)
        for equation in equations:
            if equation[1] == "!":
                index1 = ord(equation[0]) - ord("a")
                index2 = ord(equation[3]) - ord("a")
                if uf.find(index1) == uf.find(index2):
                    return False
        return True
        
# @lc code=end

