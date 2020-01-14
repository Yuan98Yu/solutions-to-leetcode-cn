#
# @lc app=leetcode.cn id=766 lang=python3
#
# [766] 托普利茨矩阵
#

# @lc code=start
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        for starting_point in [ (0,j) for j in range(n) ] + [ (i,0) for i in range(1,m) ]:
            point = starting_point
            const = matrix[point[0]][point[1]]
            while point[0]<m-1 and point[1]<n-1:
                point = (point[0]+1, point[1]+1)
                if matrix[point[0]][point[1]] != const:
                    return False
        
        return True

# @lc code=end

