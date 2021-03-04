#
# @lc app=leetcode.cn id=474 lang=python3
#
# [474] 一和零
#

# @lc code=start
from itertools import product
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        def count(s):
            zeros_num, ones_num = 0, 0
            for c in s:
                if c == '0':
                    zeros_num += 1
                else:
                    ones_num += 1
            return zeros_num, ones_num

        memo = [ [0 for _ in range(n+1)] for _ in range(m+1) ]

        for s in strs:
            zeros_num, ones_num = count(s)
            for pm, pn in product(range(m, zeros_num-1, -1), range(n, ones_num-1, -1)):
                    memo[pm][pn] = max(memo[pm][pn], 1+memo[pm-zeros_num][pn-ones_num])

        return memo[m][n]

# @lc code=end

