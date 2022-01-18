#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
from typing import List
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # return heapq.nlargest(k, nums)[-1]
        def partition(l, r):
            pivot = nums[l]

            lp, rp = l+1, r
            
            while True:
                while lp <= rp and nums[lp] > pivot:
                    lp += 1
                while rp > l and nums[rp] < pivot:
                    rp -= 1
                
                if lp >= rp:
                    break
                nums[lp], nums[rp] = nums[rp], nums[lp]
                lp += 1
                rp -= 1
        
            nums[l], nums[rp] = nums[rp], nums[l]
            return rp

        def helper(index, l, r):
            if l == r:
                return nums[l]

            p_pivot = partition(l, r)
            if p_pivot == index:
                return nums[p_pivot]
            elif p_pivot < index:
                return helper(index, p_pivot+1, r)
            else:
                return helper(index, l, p_pivot-1)

        return helper(k-1, 0, len(nums)-1)