#
# @lc app=leetcode.cn id=976 lang=python3
#
# [976] 三角形的最大周长
#
from typing import List

# @lc code=start
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A = sorted(A)
        for i in range(len(A)-1, 1, -1):
            if A[i-1] + A[i-2] > A[i]:
                return sum(A[i-2:i+1])
        
        return 0
# @lc code=end

