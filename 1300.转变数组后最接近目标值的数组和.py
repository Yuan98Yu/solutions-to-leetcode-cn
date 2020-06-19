#
# @lc app=leetcode.cn id=1300 lang=python3
#
# [1300] 转变数组后最接近目标值的数组和
#

# @lc code=start
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr = sorted(arr)
        n = len(arr)

        sum = 0
        for i in range(n):
            x = (target - sum) // (n - i)
            if x < arr[i]:
                return x if (target-sum) / (n-i) - x <= 0.5 else x+1
            sum += arr[i]
        
        return arr[-1]
# @lc code=end

