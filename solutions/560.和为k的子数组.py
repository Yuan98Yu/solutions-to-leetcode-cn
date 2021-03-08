#
# @lc app=leetcode.cn id=560 lang=python3
#
# [560] 和为K的子数组
#

# @lc code=start
from itertools import product


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        n = len(nums)

        preSumFreq = dict()
        preSumFreq[0] = 1
        sum = 0
        for num in nums:
            sum += num
            count += preSumFreq.get(sum - k, 0)
            preSumFreq[sum] = preSumFreq.get(sum, 0) + 1

        return count


# @lc code=end
