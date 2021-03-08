#
# @lc app=leetcode.cn id=793 lang=python3
#
# [793] 阶乘函数后K个零
#
# @lc code=start
class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        def five_count(n):
            if n == 0:
                return 0
            return n // 5 + five_count(n // 5)

        left, right = K, 10 * K + 1
        while left < right:
            mid = left + (right - left) // 2
            tmp = five_count(mid)
            if tmp == K:
                return 5
            elif tmp < K:
                left = mid + 1
            else:
                right = mid
        
        return 0


# @lc code=end

