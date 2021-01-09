#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#
from typing import List

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums)

        while left < right:
            mid = (left+right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        l_p = left

        if l_p < len(nums) and nums[l_p] == target:
            left, right = 0, len(nums)
            while left < right:
                mid = (left+right) // 2
                if nums[mid] > target:
                    right = mid
                else:
                    left = mid + 1
            r_p = left if left < len(nums) and nums[left] == target else left - 1
            
            return [l_p, r_p]
        else:
            return [-1, -1]
# @lc code=end

