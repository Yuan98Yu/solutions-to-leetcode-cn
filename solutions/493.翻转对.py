#
# @lc app=leetcode.cn id=493 lang=python3
#
# [493] 翻转对
#
from typing import Counter, List


# @lc code=start
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        tmp_list = [0] * len(nums)
        return self.count_and_sort(nums, 0, len(nums), tmp_list)

    def count_and_sort(self, nums, left, right, tmp_list):
        if right-left <= 1:
            return 0
        mid = (left+right) // 2

        left_count = self.count_and_sort(nums, left, mid, tmp_list)
        right_count = self.count_and_sort(nums, mid, right, tmp_list)

        return left_count + right_count + self.merge(nums, left, right, mid, tmp_list)
    
    def merge(self, nums, left, right, mid, tmp_list):
        count = 0
        i, j = left, mid
        # 在调用 merge 前，左数组和右数组皆分别排序
        for i in range(left, mid):
            while j < right and nums[i] > 2*nums[j]:
                j += 1
            count += j - mid
        
        # 归并排序
        i, j, p = left, mid, left
        while i < mid and j < right:
            if nums[i] < nums[j]:
                tmp_list[p] = nums[i]
                i += 1
            else:
                tmp_list[p] = nums[j]
                j += 1
            p += 1
        for pos in list(range(i, mid)) + list(range(j,right)):
            tmp_list[p] = nums[pos]
            p += 1
        
        for p in range(left, right):
            nums[p] = tmp_list[p]
        
        return count
        
# @lc code=end
