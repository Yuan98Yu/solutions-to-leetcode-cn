from math import sqrt


class Solution(object):
    def numSquarefulPerms(self, A: list):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = A.copy()
        nums.sort()
        ans = [0]

        def dfs(nums, pre):
            if not nums:
                ans[0] += 1
                return
            for i in range(len(nums)):
                # 去重
                if i and nums[i] == nums[i-1]:
                    continue
                # 剪枝
                if pre == -1 or sqrt(pre+nums[i]) % 1 == 0:
                    dfs(nums[:i] + nums[i+1:], nums[i])

        dfs(nums, -1)
        return ans[0]
