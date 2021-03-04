#
# @lc app=leetcode.cn id=274 lang=python3
#
# [274] H指数
#

# @lc code=start
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        h = 0
        for cite in citations:
            if cite <= h:
                break
            h += 1
        
        return h

# @lc code=end

