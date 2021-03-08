#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长上升子序列
#

# @lc code=start
class Solution:
    # def lengthOfLIS(self, nums: List[int]) -> int:
    #     '''动态规划
    #         memo[i] 表示以nums[i]为子序列尾端元素时，该上升子序列的最大长度
    #         状态：通过
    #     '''
    #     memo = list()
    #     for i in range(len(nums)):
    #         memo.append(1)
    #         for j in range(i):
    #             if nums[i] > nums[j] and memo[j] >= memo[i]:
    #                 memo[i] = memo[j] + 1
        
    #     return max(memo) if memo else 0

    def lengthOfLIS(self, nums: [int]) -> int:
        '''动态规划+二分
            tails[i] 表示长度为 i 的上升子序列，其末尾元素的最小值
            ans 表示目前最长的上升子序列长度
        '''
        tails, ans = [0] * len(nums), 0
        for num in nums:
            left, right = 0, ans
            while left < right:
                mid = (left + right) // 2
                if tails[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            tails[left] = num
            if right == ans: ans += 1
        return ans

# @lc code=end

