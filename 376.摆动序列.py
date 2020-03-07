#
# @lc app=leetcode.cn id=376 lang=python3
#
# [376] 摆动序列
#

# @lc code=start
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_length = 0
        cur_length = 1
        diff = 0
        i = 0
        for i in range(len(nums)-1):
            new_diff = nums[i+1] - nums[i]
            if new_diff == 0:
                max_length = max(max_length, cur_length)
                cur_length = 1
            elif diff == 0 or (diff ^ new_diff) < 0:
                cur_length += 1
            else:
                max_length = max(max_length, cur_length)
                cur_length = 2
            diff = new_diff
        max_length = max(max_length, cur_length)
        return max_length

# @lc code=end

