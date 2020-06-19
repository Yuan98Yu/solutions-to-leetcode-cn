#
# @lc app=leetcode.cn id=1014 lang=python3
#
# [1014] 最佳观光组合
#


# @lc code=start
class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        max_ans = 0
        max_i = A[0]
        for j in range(1, len(A)):
            max_ans = max(max_ans, A[j] - j + max_i)
            max_i = max(max_i, A[j] + j)

        return max_ans


# @lc code=end
