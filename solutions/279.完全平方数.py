#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    # def numSquares(self, n: int) -> int:
    #     '''动态规划 超时'''
    #     dp = [i for i in range(n+1)]
        
    #     for i in range(1, n+1):
    #         for j in range( 1, int(sqrt(i))+1 ):
    #             dp[i] = min( dp[i], dp[i - j**2]+1 )

    #     return dp[n]

    def numSquares(self, n: int) -> int:
        '''BFS'''
        from collections import deque
        if n == 0: return 0
        queue = deque([n])
        step = 0
        visited = set()
        while(queue):
            step+=1
            l=len(queue)
            for _ in range(l):
                tmp=queue.pop()
                for i in range(1,int(tmp**0.5)+1):
                    x=tmp-i**2
                    if(x==0):
                        return step
                    if(x not in visited):
                        queue.appendleft(x)
                        visited.add(x)
        return step

# @lc code=end

