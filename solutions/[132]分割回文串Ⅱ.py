from typing import *
from itertools import product


class Solution:
    def minCut(self, s: str) -> int:
        pass

    def partition(self, s: str) -> List[List[str]]:
        memo = [[None] * len(s) for _ in range(len(s))]
        for i in range(len(s)):
            memo[i][i] = list()
            memo[i][i].append([s[i]])

        def dfs(l, r):
            if l > r:
                return [[]]
            if memo[l][r] is not None:
                return memo[l][r]

            memo[l][r] = list()
            for mid in range(l+1, r+2):
                if self._is_palindrome(s, l, mid-1):
                    l_list = [s[l:mid]]
                    r_list = dfs(mid, r)
                    # print(l, r, mid, l_list, r_list)
                    for item in r_list:
                        memo[l][r].append(l_list + item)

            return memo[l][r]

        dfs(0, len(s) - 1)
        return memo[0][len(s) - 1]

    def _is_palindrome(self, s: str, l: int, r: int):
        while l <= r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
