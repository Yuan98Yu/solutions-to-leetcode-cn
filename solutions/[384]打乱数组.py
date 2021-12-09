import random
from typing import List


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums.copy()
        self.origin = nums

    def reset(self) -> List[int]:
        self.nums = self.origin.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        for i in range(0, len(self.origin)):
            j = random.randint(i, len(self.origin) - 1)
            self.nums[i], self.nums[j] = self.nums[j], self.nums[i]

        return self.nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()