from typing import List


class Solution:
    '''排序后，双指针'''
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        total, max_frequency = 0, 1
        l = 0
        for r in range(1, len(nums)):
            total += (nums[r] - nums[r - 1]) * (r - l)
            while total > k:
                total -= nums[r] - nums[l]
                l += 1
            max_frequency = max(max_frequency, r - l + 1)

        return max_frequency


class Solution2:
    '''排序后，线性查找。超时了...'''
    def maxFrequency(self, nums: List[int], k: int) -> int:
        value2count_dict = dict()
        for num in nums:
            value2count_dict[num] = value2count_dict.get(num, 0) + 1
        value2count_list = sorted([(k, v)
                                   for k, v in value2count_dict.items()],
                                  key=lambda item: item[0])
        return max([
            self._get_max_frequency(value2count_list, i, k)
            for i in range(len(value2count_list))
        ])

    def _get_max_frequency(self, value2count_list, i, k):
        value, count = value2count_list[i]

        frequency = count
        idx = i - 1
        while idx >= 0 and k > 0:
            cur_value, cur_count = value2count_list[idx]
            added_frequency = min(cur_count, k // (value - cur_value))
            frequency += added_frequency
            k -= added_frequency * (value - cur_value)
            idx -= 1

        return frequency
