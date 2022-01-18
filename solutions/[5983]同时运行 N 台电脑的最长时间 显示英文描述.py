from typing import List


class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort()
        res = sum(batteries[:-n])
        i = len(batteries)-n+1
        while res > 0 and i < len(batteries):
            print(res, i)
            
            tmp = (batteries[i] - batteries[i-1]) * (i-len(batteries)+n)
            if tmp <= res:
                batteries[i-1] = batteries[i]
                res -= tmp
            else:
                batteries[i-1] += res // (i-len(batteries)+n)
                batteries[i] = batteries[i-1]
                res = 0
            i += 1
        return batteries[i-1] + res // n
