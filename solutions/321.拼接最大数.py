#
# @lc app=leetcode.cn id=321 lang=python3
#
# [321] 拼接最大数
#
from typing import List

# @lc code=start


class Solution:
    # def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
    #     def dfs(i, j, k):
    #         if k == 0:
    #             return []
    #         p1, v1 = -1, -1
    #         p2, v2 = -1, -1
    #         # len(nums1) - idx-1 >= k-1 - (len(nums2) - j)
    #         # idx <= len(nums1) + len(nums2) - j -k
    #         for idx in range(i,
    #                          min(len(nums1),
    #                              len(nums1) + len(nums2) - j - k + 1)):
    #             if nums1[idx] > v1:
    #                 p1, v1 = idx, nums1[idx]
    #         for idx in range(j,
    #                          min(len(nums2),
    #                              len(nums1) + len(nums2) - i - k + 1)):
    #             if nums2[idx] > v2:
    #                 p2, v2 = idx, nums2[idx]
    #         # print(v1, v2)
    #         if v1 == v2:
    #             return [v1] + max(dfs(p1+1, j, k-1), dfs(i, p2+1, k-1))
    #         elif v1 > v2:
    #             return [v1] + dfs(p1+1, j, k-1)
    #         else:
    #             return [v2] + dfs(i, p2+1, k-1)

    #     return dfs(0, 0, k)

    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def get_max(nums, k):
            stack = list()
            for i in range(0, len(nums)):
                if len(stack) + len(nums) - i == k:
                    break

                v = nums[i]
                while stack and len(stack) + len(nums) - i - 1 >= k and v > stack[-1]:
                    stack.pop()
                stack.append(v)
            return stack[:k] if len(stack) >= k else stack + nums[-(k-len(stack)):]
        
        def merge(nums1, nums2):
            ans = list()
            p1, p2 = 0, 0
            while p1 < len(nums1) and p2 < len(nums2):
                if nums1[p1:] > nums2[p2:]:
                    ans.append(nums1[p1])
                    p1 += 1
                else:
                    ans.append(nums2[p2])
                    p2 += 1
            if p1 < len(nums1):
                ans.extend(nums1[p1:])
            if p2 < len(nums2):
                ans.extend(nums2[p2:])
            return ans

        ans = list()
        for k1 in range(max(0, k - len(nums2)), min(len(nums1), k)+1):
            ans = max(ans, merge(get_max(nums1, k1), get_max(nums2, k-k1)))
        
        return ans
# @lc code=end
