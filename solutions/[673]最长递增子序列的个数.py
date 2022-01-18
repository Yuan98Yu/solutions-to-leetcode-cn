from typing import List


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        len_memo = [1] * n
        count_memo = [1] * n

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if len_memo[j] + 1 > len_memo[i]:
                        len_memo[i] = len_memo[j] + 1
                        count_memo[i] = count_memo[j]
                    elif len_memo[j] + 1 == len_memo[i]:
                        count_memo[i] += count_memo[j]