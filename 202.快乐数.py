#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#

# @lc code=start
from functools import reduce


class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        def help(n: int):
            print(n)
            if n==1:
                return True
            elif n in s:
                return False
            else:
                s.add(n)
                n = reduce(lambda sum, value : sum+int(value)**2, list(str(n)), 0)
                return help(n)
        
        return help(n)
            
        
        
# @lc code=end

