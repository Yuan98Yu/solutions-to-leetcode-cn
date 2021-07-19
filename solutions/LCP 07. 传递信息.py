from typing import List


class Solution:
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        def dfs(cur: int, k: int, times: int) -> int:
            if k == 0:
                return 1 if cur == n - 1 else 0

            count = 0
            for x, y in relation:
                if x == cur:
                    count += dfs(y, k - 1, times)
            return count * times

        return dfs(0, k, 1)
