#
# @lc app=leetcode.cn id=791 lang=python3
#
# [791] 自定义字符串排序
#

# @lc code=start
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        ans = ''
        counts = [0] * 26
        for c in T:
            counts[ord(c)-ord('a')] += 1

        for c in S:
            count = counts[ord(c)-ord('a')]
            ans += c * count
            counts[ord(c)-ord('a')] = -1

        rest = ''
        for c in T:
            if counts[ord(c)-ord('a')] != -1:
                rest += c

        ans += rest
        return ans
        
        
# @lc code=end

