#
# @lc app=leetcode.cn id=149 lang=python3
#
# [149] 直线上最多的点数
#

# @lc code=start
from math import sqrt
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        dict_slope2count = dict()
        dict_slope2count[0] = 0
        dict_count_of_vertical = dict()
        dict_count_of_vertical[0] = 0
        for i in range(n):
            p1 = points[i]
            for j in range(i+1, n):
                p2 = points[j]
                if p1 == p2:
                    continue
                if p1[0] == p2[0]:
                    count = dict_count_of_vertical.get(p1[0], 0)
                    dict_count_of_vertical[p1[0]] = count + 1
                else:
                    slope = (p2[1]-p1[1])/(p2[0]-p1[0])
                    count = dict_slope2count.get(slope, 0)
                    dict_slope2count[slope] = count + 1
        tmp = max(max(dict_slope2count.values()),max(dict_count_of_vertical.values()))
        if tmp == 0:
            return len(points)
        return int(sqrt(tmp*2)) +1

# @lc code=end

