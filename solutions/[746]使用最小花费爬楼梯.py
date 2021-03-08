from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """ dp 法
        """

        memo = cost[:2]
        for i in range(2, len(cost)):
            tmp = min(memo[0], memo[1]) + cost[i]
            memo[0], memo[1] = memo[1], tmp

        return min(memo[0], memo[1])