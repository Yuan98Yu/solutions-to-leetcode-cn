from typing import List
from itertools import product


class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        # 以下等价于 count_map = collections.Counter(u+v for u in A for v in B)
        count_map = dict()
        for num3, num4 in product(C, D):
            target = num3 + num4
            count = count_map.get(target, 0)
            count_map[target] = count + 1

        ans = 0
        for num1, num2 in product(A, B):
            target = -num1 - num2
            ans += count_map.get(target, 0)

        return ans
