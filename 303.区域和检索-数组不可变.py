#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#

# @lc code=start
from functools import reduce
class NumArray:
    def __init__(self, nums: List[int]):
        self.memo = list()
        sum = 0
        for num in nums:
            sum += num
            self.memo.append(sum)

    def sumRange(self, i: int, j: int) -> int:
        right = self.memo[j]
        left = self.memo[i-1] if i > 0 else 0
        return right - left


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
# @lc code=end

