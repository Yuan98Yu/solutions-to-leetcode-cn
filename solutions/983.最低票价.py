#
# @lc app=leetcode.cn id=983 lang=python3
#
# [983] 最低票价
#


# @lc code=start
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        days_set = set(days)
        memo = [-1] * 366  # 从第 i 天开始到年末所需的最低消费

        def dp(i):
            if i > 365:
                return 0
            if memo[i] != -1:
                return memo[i]

            if i in days_set:
                memo[i] = min(
                    dp(i + 1) + costs[0],
                    dp(i + 7) + costs[1], dp(i + 30) + costs[2])
            else:
                memo[i] = dp(i + 1)

            return memo[i]

        return dp(1)
# @lc code=end
