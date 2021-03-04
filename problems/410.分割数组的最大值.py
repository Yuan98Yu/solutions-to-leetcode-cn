#
# @lc app=leetcode.cn id=410 lang=python3
#
# [410] 分割数组的最大值
#


# @lc code=start
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l, r = max(nums), sum(nums)+1
        mid = r
        while l < r:
            mid = (l + r) // 2
            # print(mid)

            tmp_sum = 0
            count = 1
            for i in range(len(nums)):
                if tmp_sum + nums[i] <= mid:
                    tmp_sum += nums[i]
                else:
                    tmp_sum = nums[i]
                    count += 1
                    # print(i)
                    if count > m:
                        # print(mid, 'break')
                        break

            if count <= m:
                # print(l, r)
                r = mid
            else:
                l = mid + 1

        return l

# @lc code=end
