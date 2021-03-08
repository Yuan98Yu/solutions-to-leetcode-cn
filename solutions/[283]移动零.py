from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nonzero_count = 0
        for i, num in enumerate(nums):
            if num != 0:
                nums[nonzero_count] = num
                nonzero_count += 1
        
        for i in range(nonzero_count, len(nums)):
            nums[i] = 0
        
        return nums
