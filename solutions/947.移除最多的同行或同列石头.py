#
# @lc app=leetcode.cn id=947 lang=python3
#
# [947] 移除最多的同行或同列石头
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
        self.p[xr] = yr


class Solution(object):
    def removeStones(self, stones):
        N = len(stones)
        dsu = DSU(20000)
        for x, y in stones:
            dsu.union(x, y + 10000)

        return N - len({dsu.find(x) for x, _ in stones})
# @lc code=end

