from typing import List


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)

        prevdiff = nums[1] - nums[0]
        ans = (2 if prevdiff != 0 else 1)
        for i in range(2, len(nums)):
            diff = nums[i] - nums[i - 1]
            if (diff > 0 and prevdiff <= 0) or (diff < 0 and prevdiff >= 0):
                ans += 1
                prevdiff = diff

        
        return ans