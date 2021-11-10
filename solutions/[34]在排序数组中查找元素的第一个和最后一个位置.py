from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l_p, r_p = -1, -1
        l, r = 0, len(nums)
        while l < r:
            mid = (l+r) // 2
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid
        if l < len(nums) and nums[l] == target:
            l_p = l
            l, r = 0, len(nums)
            while l < r:
                mid = (l+r) // 2
                if nums[mid] > target:
                    r = mid
                else:
                    l = mid + 1
            r_p = l-1

        return l_p, r_p