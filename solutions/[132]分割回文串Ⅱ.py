class Solution:
    def minCut(self, s: str) -> int:
        memo = [[None] * len(s) for _ in range(len(s))]
        for i in range(0, len(s)):
            memo[i][i] = 0
        for length in range(2, len(s)+1):
            for i in range(0, len(s)-length+1):
                j = i + length - 1
                if s[i] == s[j] and (length == 2 or memo[i+1][j-1] == 0):
                    memo[i][j] = 0

        def dfs(l, r):
            if l >= r:
                return 0
            if memo[l][r] is not None:
                return memo[l][r]

            memo[l][r] = float('inf')
            for mid in range(l+1, r+1):
                if memo[l][mid-1] == 0:
                    memo[l][r] = min(memo[l][r], 1 + dfs(mid, r))

            return memo[l][r]

        return dfs(0, len(s)-1)