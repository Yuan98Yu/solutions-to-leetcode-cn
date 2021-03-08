"""
    unsolved
"""


class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        dp = dict()

        def dfs(n, m):
            if n == m:
                return 1
            if n == 0 or m == 0:
                return 0
            if dp.get((n, m)) is not None:
                return dp.get((n, m))

            ans = 2e8
            for i in range(1, min(n, m) + 1):
                res1 = dfs(n-i, m) + dfs(i, m-i)
                res2 = dfs(n, m-i) + dfs(n-i, i)
                ans = min(ans, res1, res2) + 1

            dp[(n, m)] = ans
            return ans

        return dfs(n, m)
