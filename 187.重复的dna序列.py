#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#

# @lc code=start
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        """A basic solution, status: succeed"""
        ans = list()
        s2count = dict()
        for i in range( len(s)-9 ):
            tmp = s[i:i+10]
            s2count[tmp] = s2count.get(tmp, 0) + 1
        for v, i in s2count.items():
            if i > 1:
                ans.append(v)
        
        return ans

# @lc code=end

