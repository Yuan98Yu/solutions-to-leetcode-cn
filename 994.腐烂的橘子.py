#
# @lc app=leetcode.cn id=994 lang=python3
#
# [994] 腐烂的橘子
#

# @lc code=start
from itertools import product
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) if grid else 0
        queue = list()

        fresh_count = 0
        for i, j in product(range(m), range(n)):
            if grid[i][j] == 2:
                queue.append([i, j])
            elif grid[i][j] == 1:
                fresh_count += 1
        
        time = 0
        while queue:
            queue_len = len(queue)
            forward = 0
            for c in range(queue_len-1, 0-1, -1):
                i, j = queue.pop(c)
                for dir in [(-1,0), (1,0), (0,-1), (0,1)]:
                    new_pos = [i+dir[0], j+dir[1]]
                    if 0 <= new_pos[0] < m and 0 <= new_pos[1] < n \
                    and grid[new_pos[0]][new_pos[1]] == 1:
                        forward = 1
                        fresh_count -= 1
                        grid[new_pos[0]][new_pos[1]] = 2
                        queue.append(new_pos)
            time += forward

        return -1 if fresh_count != 0 else time


# @lc code=end

