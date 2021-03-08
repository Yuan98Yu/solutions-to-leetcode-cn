#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#


# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        outputs = [1] * n

        for i in range(n - 1):
            outputs[i + 1] = outputs[i] * nums[i]

        product = 1
        for i in range(n - 1, 0, -1):
            product *= nums[i]
            outputs[i - 1] *= product

        return outputs


# @lc code=end
