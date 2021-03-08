#
# @lc app=leetcode.cn id=908 lang=python3
#
# [908] 最小差值 I
#

# @lc code=start
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        min_num, max_num = min(A), max(A)
        return 0 if max_num-min_num <= 2*K else max_num-min_num-2*K
# @lc code=end

