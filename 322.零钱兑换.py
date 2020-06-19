#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [-1] * (amount+1)
        memo[0] = 0
        coins = set(coins)
        for coin in coins:
            if coin <= amount:
                memo[coin] = 1

        def dp(amount):
            if memo[amount] != -1:
                return memo[amount]
            
            ans = float('inf')
            for coin in coins:
                res = amount - coin
                if res >= 0:
                    ans = min(ans, 1 + dp(res))

            memo[amount] = ans
            return ans
        
        ans = dp(amount)
        return ans if ans != float('inf') else -1
                
# @lc code=end

