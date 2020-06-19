#
# @lc app=leetcode.cn id=837 lang=python3
#
# [837] 新21点
#


# @lc code=start
class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        memo = [None] * (K + W)
        s = 0
        for i in range(K, K + W):
            memo[i] = 1 if i <= N else 0
            s += memo[i]

        for i in range(K - 1, -1, -1):
            memo[i] = s / W
            s = s + memo[i] - memo[i + W]

        return memo[0]


# @lc code=end
