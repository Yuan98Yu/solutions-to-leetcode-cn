#
# @lc app=leetcode.cn id=835 lang=python3
#
# [835] 图像重叠
#

# @lc code=start
from itertools import product
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        m, n = len(A), len(A[0]) if A else 0
        max_count = 0
        for delta_i, delta_j in product( range(m), range(n) ):
            count1 = count2 = 0
            for i, j in product( range(m-delta_i), range(n-delta_j) ):
                new_i, new_j = (i+delta_i), (j+delta_j)
                if A[i][j] == B[new_i][new_j] == 1:
                    count1 += 1
                if B[i][j] == A[new_i][new_j] == 1:
                    count2 += 1
            max_count = max(max_count, count1, count2)
        return max_count
        
# @lc code=end

