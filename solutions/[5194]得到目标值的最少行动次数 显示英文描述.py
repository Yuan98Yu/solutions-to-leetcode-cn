class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        # memo = [[0]*maxDoubles for _ in range(target+1)]
        
        # def dp_helper(target, max_doubles):
        #     if memo[target][max_doubles] != 0:
        #         return memo[target][max_doubles]
            
        #     return 1 + min()
        ans = 0
        val = target
        while val != 1 and maxDoubles > 0:
            ans += 1 + (val & 1)
            val //= 2
            maxDoubles -= 1
        return ans + val - 1
    