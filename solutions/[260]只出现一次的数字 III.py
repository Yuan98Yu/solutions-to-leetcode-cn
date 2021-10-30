from typing import List
from functools import reduce


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        a_xor_b = reduce(lambda x, y: x ^ y, nums)

        l_flag = a_xor_b & -a_xor_b
        flag1, flag2 = 0, 0
        for num in nums:
            if num & l_flag:
                flag1 ^= num
            else:
                flag2 ^= num
        return flag1, flag2