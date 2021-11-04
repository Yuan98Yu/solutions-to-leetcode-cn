from typing import List


class Solution:
    # recursion
    def lexicalOrder(self, n: int) -> List[int]:
        ans = list()

        def dfs(cur):
            if cur > n:
                return
            ans.append(cur)
            for i in range(10):
                dfs(cur*10 + i)
        
        for i in range(1, 10):
            dfs(i)
        return ans
    
    # loop
    def lexicalOrder2(self, n: int) -> List[int]:
        ans = list()

        cur = 1
        while len(ans) < n:
            while cur <= n:
                ans.append(cur)
                cur *= 10

            while cur >= n or cur %10 == 9:
                cur //= 10
            cur += 1
        return ans