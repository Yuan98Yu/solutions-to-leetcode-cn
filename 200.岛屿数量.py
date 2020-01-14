#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#

# @lc code=start
from itertools import product
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def is_valid(i, j):
            return 0<=i<len(grid) and 0<=j<len(grid[0])
        def dfs(i, j):
            if is_valid(i, j) and grid[i][j] == '1':
                grid[i][j] = '0'
                for dir_i, dir_j in ( (-1,0), (1,0), (0,-1), (0,1) ):
                    dfs(i+dir_i, j+dir_j)
        
        if not grid or not grid[0]:
            return 0
        count = 0
        for i, j in product( range(len(grid)), range(len(grid[0])) ):
            if grid[i][j] == '1':
                count += 1
                dfs(i ,j)
        return count

# @lc code=end

