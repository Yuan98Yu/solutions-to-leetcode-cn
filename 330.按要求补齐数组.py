#
# @lc app=leetcode.cn id=330 lang=python3
#
# [330] 按要求补齐数组
#

# @lc code=start
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        ans = 0
        miss = 1
        i = 0

        while miss <= n:
            if i < len(nums) and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                miss *= 2
                ans += 1

        return ans 
                

# @lc code=end

