from typing import List


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        min_m, min_n = m, n
        for a, b in ops:
            min_m = min(min_m, a)
            min_n = min(min_n, b)

        return min_m * min_n