#
# @lc app=leetcode.cn id=1035 lang=python3
#
# [1035] 不相交的线
#

# @lc code=start
from itertools import product
class Solution:
    # def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
    #     '''穷举法，超时
    #     '''
    #     # 初始化一个字典 B_memo
    #     # B_memo 的键是一个数值，值是一个数组
    #     # 这一步是遍历数组 B，统计数组 B 中出现的各个值对应的下标（一个值可能出现多次，所以用数组）
    #     B_memo = dict()
    #     for i in range(len(B)):
    #         records = B_memo.get(B[i], [])
    #         records.append(i)
    #         B_memo[B[i]] = records

    #     def dp(A_idx, max_B_idx):
    #         ''' 遍历数组 A 的子数组 A[A_idx:]
    #             parameters:
    #                 A_idx: 当前子数组的开头
    #                 max_B_idx: 之前已选择的 B 数组中最大的索引，之后选择的 B 数组中的元素的索引必须大于它，否则相交
    #         '''
    #         if A_idx == len(A):
    #             return 0

    #         val = A[A_idx]
    #         records = B_memo.get(val, None)
    #         if records is None:
    #             return dp(A_idx+1, max_B_idx)
    #         else:
    #             i = 0
    #             while i < len(records) and records[i] <= max_B_idx:
    #                 i += 1
    #             if i == len(records):
    #                 return dp(A_idx+1, max_B_idx)
    #             else:
    #                 tmp1 = dp(A_idx+1, max_B_idx)
    #                 tmp2 = 1+dp(A_idx+1, records[i])
    #                 return max(tmp1, tmp2)
        
    #     return dp(0, -1)

    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        '''动态规划, 通过'''
        m, n = len(A), len(B)
        memo = [ [0 for _ in range(n+1)] for _ in range(m+1) ] 
        for i in range(m+1):
            memo[i][0] = 0
        for j in range(1, n+1):
            memo[0][j] = 0

        for i, j in product(range(1, m+1), range(1, n+1)):
            if A[i-1] == B[j-1]:
                memo[i][j] = memo[i-1][j-1] + 1
            else:
                memo[i][j] = max(memo[i-1][j], memo[i][j-1])

        return memo[m][n]

# @lc code=end

