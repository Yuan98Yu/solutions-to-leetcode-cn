#
# @lc app=leetcode.cn id=1371 lang=python3
#
# [1371] 每个元音包含偶数次的最长子字符串
#

# @lc code=start
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        n = len(s)
        vowels = ['a', 'e', 'i', 'o', 'u']

        start, end = 0, n - 1
        count = dict()
        for letter in vowels:
            count[letter] = 0
        
        for c in s:
            if c in vowels:
                count[c] += 1
            valid = True
            for letter in vowels:
                if count[letter] %2 != 0
                    valid = False
                    break
            if valid:
                return n
        
        while start <= end:
            
        
# @lc code=end

