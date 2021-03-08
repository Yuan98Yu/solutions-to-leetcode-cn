#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        strs1 = version1.split('.')
        strs2 = version2.split('.')
        n1, n2 = len(strs1), len(strs2)
        flag = 1
        if n1 > n2:
            strs1, strs2 = strs2, strs1
            n1, n2 = n2, n1
            flag = -1
        for i in range(n1):
            num1 = int(strs1[i])
            num2 = int(strs2[i])
            if num1 == num2:
                continue
            elif num1 > num2:
                return flag
            else:
                return -flag
        for s in strs2[n1:]:
            if int(s) != 0:
                return -flag
        return 0

        
# @lc code=end

