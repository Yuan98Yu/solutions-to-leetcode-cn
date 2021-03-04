#
# @lc app=leetcode.cn id=1103 lang=python3
#
# [1103] 分糖果 II
#

# @lc code=start
from math import sqrt, floor
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n = floor(sqrt(2 * candies))
        while n*(n+1) > 2*candies:
            n -= 1
        round = n // num_people
        rest = n % num_people
        
        ans = list()
        k = (1+round)*round // 2
        share = k * num_people
        for i in range(1, rest+1):
            candy_num = share + (round+1) * i
            ans.append(candy_num)
        
        k = round * (round-1) // 2
        share = k * num_people
        candy_num = candies - (1+n)*n // 2 + share + round * (rest+1)
        ans.append(candy_num)
        for i in range(rest+2, num_people+1):
            candy_num = share + round * i
            ans.append(candy_num)
        
        return ans
        
# @lc code=end

