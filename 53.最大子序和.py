#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if not nums:
            return float('-inf')
        
        mid = len(nums) // 2
        left_sum = self.maxSubArray(nums[:mid])
        right_sum = self.maxSubArray(nums[mid+1:])
        cross_sum = self.merge(nums, mid)

        return max(left_sum, right_sum, cross_sum)
        
    def merge(self, nums, p):
        ans = nums[p]
        left_max_sum = 0
        sum = 0
        for i in range(p-1, 0-1, -1):
            sum += nums[i]
            left_max_sum = max(left_max_sum, sum)

        right_max_sum = 0
        sum = 0
        for num in nums[p+1:]:
            sum += num
            right_max_sum = max(right_max_sum, sum)
        return left_max_sum + ans + right_max_sum

# @lc code=end

