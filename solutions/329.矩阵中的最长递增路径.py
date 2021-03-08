#
# @lc app=leetcode.cn id=329 lang=python3
#
# [329] 矩阵中的最长递增路径
#

# @lc code=start
from itertools import product
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0]) if matrix else 0

        memo = [[-1]*n for i in range(m)]
        def df(x, y):
            if memo[x][y] != -1:
                return memo[x][y]

            max_len = 1
            cur_val = matrix[x][y]
            for dir in [(-1,0), (1,0), (0,-1), (0,1)]:
                new_x, new_y = x+dir[0], y+dir[1]
                if 0 <= new_x < m and 0 <= new_y < n:
                    new_val = matrix[new_x][new_y]
                    if new_val > cur_val:
                        max_len = max(max_len, 1+df(new_x, new_y))
            memo[x][y] = max_len
            return max_len
        
        max_len = 0
        for x, y in product(range(m), range(n)):
            max_len = max(max_len, df(x, y))
        return max_len

# @lc code=end

