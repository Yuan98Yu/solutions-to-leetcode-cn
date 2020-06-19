#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left+right) // 2
            smallers = 0
            for num in nums:
                if num <= mid:
                    smallers += 1

            if smallers > mid:
                right = mid
            else:
                left = mid + 1
        
        return left


# @lc code=end

