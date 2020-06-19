#
# @lc app=leetcode.cn id=638 lang=python3
#
# [638] 大礼包
#

# @lc code=start
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        n = len(needs)
        def dfs(needs):
            i = 0
            for need in needs:
                if need < 0:
                    return float('inf')
            while i < n:
                if needs[i] > 0:
                    break
                i += 1
            if i == n:
                return 0
            
            needs[i] -= 1
            ans = price[i] + dfs(needs)
            needs[i] += 1
            for s in special:
                if s[i] > 0:
                    for i in range(n):
                        needs[i] -= s[i]
                    ans = min(ans, dfs(needs)+s[n])
                    for i in range(n):
                        needs[i] += s[i]
            return ans

        return dfs(needs)            

# @lc code=end

