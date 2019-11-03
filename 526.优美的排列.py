class Solution:
    def countArrangement(self, N: int) -> int:
        visited = [False] * (N + 1)
        def dfs(pos: int) -> int:
            if pos == N + 1:
                return 1
            ans = 0
            for i in range(1, N+1):
                if not visited[i] and (pos % i == 0 or i % pos ==0):
                    visited[i] = True
                    ans += dfs(pos + 1)
                    visited[i] = False
            return ans
        return dfs(1)