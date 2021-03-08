from typing import *


class Solution:
    def minCut(self, s: str) -> int:
        memo = [[None] * len(s) for _ in range(len(s))]

        def dfs(l, r):
            if l >= r:
                return 0
            if memo[l][r] is not None:
                return memo[l][r]

            memo[l][r] = float('inf')
            if self._is_palindrome(s, l, r):
                memo[l][r] = 0
            else:
                for mid in range(l+1, r+1):
                    if self._is_palindrome(s, l, mid-1):
                        memo[l][r] = min(memo[l][r], 1+ dfs(mid, r))

            return memo[l][r]

        return dfs(0, len(s) - 1)

    def _is_palindrome(self, s: str, l: int, r: int):
        while l <= r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
