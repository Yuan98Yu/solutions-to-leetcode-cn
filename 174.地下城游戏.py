#
# @lc app=leetcode.cn id=174 lang=python3
#
# [174] 地下城游戏
#

# @lc code=start
from itertools import product


class Solution:
    # def calculateMinimumHP1(self, dungeon: List[List[int]]) -> int:
    #     """带备忘录的 dfs, Status:Succeed"""
    #     m, n = len(dungeon), len(dungeon[0])
    #     dp = [ [0] * n for i in range(m)]   # hp needed to arrive destination
    #     dp[-1][-1] = max(1-dungeon[-1][-1], 1)
    #     def is_valid_pos(pos):
    #         return 0 <= pos[0] < m and 0 <= pos[1] < n
    #     def dfs(pos):
    #         x, y = pos
    #         if dp[x][y] != 0:
    #             return dp[x][y]

    #         next_needs = list()
    #         for next_pos in [(x+1, y), (x, y+1)]:
    #             if is_valid_pos(next_pos):
    #                 next_needs.append( dfs(next_pos) )
    #         next_need = min(next_needs)
    #         dp[x][y] = max(next_need - dungeon[x][y], 1)      
            
    #         return dp[x][y]

    #     dfs((0, 0))
    #     print(dp)
    #     return dp[0][0]
    
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        """dfs 改写成 dp, status:succeed"""
        m, n = len(dungeon), len(dungeon[0])
        def is_valid_pos(pos):
            return 0 <= pos[0] < m and 0 <= pos[1] < n
        
        dp = [ [0] * n for i in range(m)]   # hp needed to arrive destination
        dp[-1][-1] = max(1-dungeon[-1][-1], 1)
        for i, j in product(range(m-1, -1, -1), range(n-1, -1, -1)):
            if i == m-1 and j == n-1:
                continue
            next_needs = list()
            for next_pos in [(i+1, j), (i, j+1)]:
                if is_valid_pos(next_pos):
                    next_needs.append(dp[next_pos[0]][next_pos[1]])
            next_need = min(next_needs)
            dp[i][j] = max(next_need - dungeon[i][j], 1)
        
        return dp[0][0]


# @lc code=end

