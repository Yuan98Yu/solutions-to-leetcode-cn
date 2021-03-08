class Solution:
    def translateNum(self, num: int) -> int:
        str_num = str(num)
        n = len(str_num)
        memo = [ -1 for _ in range(n+1)]
        memo[n-1] = 1
        memo[n] = 1
        def dfs(i):
            if memo[i] != -1:
                return memo[i]
            
            ans = 0
            if i < n-1 and str_num[i] != '0' and int(str_num[i:i+2]) < 26:
                ans = dfs(i+1) + dfs(i+2)
            else:
                ans = dfs(i+1)
            
            memo[i] = ans
            return ans

        return dfs(0)
