from typing import List


class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        memo = dict()
        for num in arr:
            memo[num] = memo.get(num - difference, 0) + 1

        return max(memo.values())
