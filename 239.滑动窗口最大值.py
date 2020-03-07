#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k > len(nums) or k <= 0:
            return []

        window = list()
        def append_window(idx):
            while window and window[0] <= idx-k:
                window.pop(0)
            while window and nums[window[-1]] < nums[idx]:
                window.pop() 
            window.append(idx)

        for i in range(0, k-1):
            append_window(i)

        ans = list()
        for i in range(k-1, len(nums)):
            append_window(i)
            ans.append(nums[window[0]])
        
        return ans
        
# @lc code=end

