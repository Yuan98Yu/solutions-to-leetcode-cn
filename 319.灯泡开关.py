#
# @lc app=leetcode.cn id=319 lang=python3
#
# [319] 灯泡开关
#

# @lc code=start
from math import sqrt, floor
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return floor(sqrt(n))
# @lc code=end

