#
# @lc app=leetcode.cn id=712 lang=python3
#
# [712] 两个字符串的最小ASCII删除和
#

# @lc code=start
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        memo = [[-1 for j in range(len(s2)+1)] for i in range(len(s1)+1)]
        memo[0][0] = 0
        for i in range(len(s1)):
            memo[i+1][0] = ord(s1[i]) + memo[i][0]
        for j in range(len(s2)):
            memo[0][j+1] = ord(s2[j]) + memo[0][j]

        
        def dp(len1, len2):
            if memo[len1][len2] != -1:
                return memo[len1][len2]
            
            i, j = len1-1, len2-1
            if s1[i] == s2[j]:
                distance = dp(len1-1, len2-1)
            else:
                distance = min(dp(len1-1, len2) + ord(s1[i]),
                dp(len1, len2-1) + ord(s2[j]))
            memo[len1][len2] = distance
            return distance
        
        return dp(len(s1), len(s2))

# @lc code=end

