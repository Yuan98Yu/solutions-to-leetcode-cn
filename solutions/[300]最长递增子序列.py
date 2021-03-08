from typing import *


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        memo = [1] * len(nums)

        for i in range(1, len(nums)):
            num = nums[i]
            for j, pre_num in enumerate(nums[:i]):
                if num > pre_num:
                    memo[i] = max(memo[i], memo[j] + 1)

        return max(memo)    
