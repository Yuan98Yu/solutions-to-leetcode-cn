#
# @lc app=leetcode.cn id=152 lang=python3
#
# [152] 乘积最大子序列
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        def help(start=0, stop=n, step= 1) -> int:
            res = nums[0]
            prod = 1   
            for i in range(start, stop, step):
                if nums[i] == 0:
                    prod = 1
                    res = max((res, 0))
                else:
                    prod *= nums[i]
                    res = max((res, prod))
            return res

        return max( (help(), help(n-1, -1, -1)) )
        
# @lc code=end

