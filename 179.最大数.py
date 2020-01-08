#
# @lc app=leetcode.cn id=179 lang=python3
#
# [179] 最大数
#

# @lc code=start
from math import log10, ceil

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        """????? reference: https://leetcode-cn.com/problems/largest-number/solution/python-ji-bai-999-bing-bu-shi-yong-ren-he-zi-fu-ch/"""

        def i2i(num):
            if num == 0:
                return 0
            s = ceil(log10(num+1))
            k = num
            return k /( 10 **s -1)
        
        nums = sorted(nums, key=i2i, reverse=True)
        if nums[0] == 0:
            return '0'
        else:
            return ''.join([str(num) for num in nums])


# @lc code=end

