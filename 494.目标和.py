#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if S > 1000 or S < -1000:
            return 0

        n = len(nums)
        memo = [ [-1 for _ in range(4001)] for _ in range(n) ]

        def dfs(target, p):
            if p == n:
                if target == 0:
                    return 1
                else:
                    return 0
            if memo[p][target+1000] != -1:
                return memo[p][target+1000]
            memo[p][target+1000] = dfs(target-nums[p], p+1) + dfs(target+nums[p], p+1)
            return memo[p][target+1000]

        return dfs(S, 0)
        
# @lc code=end

