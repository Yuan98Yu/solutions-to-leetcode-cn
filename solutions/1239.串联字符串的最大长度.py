class Solution:
    def maxLength(self, arr: list) -> int:
        def dfs(start: int, path: set):
            ans = len(path)
            for i in range(start, len(arr)):
                tmp = path.union(arr[i])
                if len(tmp) != len(path) + len(arr[i]):
                    continue
                else:
                    res = dfs(i+1, tmp)
                    ans = max(ans, res)
            return ans

        return dfs(0, set())
