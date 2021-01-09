#
# @lc app=leetcode.cn id=659 lang=python3
#
# [659] 分割数组为连续子序列
#
from typing import List
# @lc code=start
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1] + 1:
                count += 1
            elif count < 3:
                break
            else:
                count = 1
        return count >= 3
# @lc code=end

