#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#

# @lc code=start
class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        l, r = 0, len(s)-1
        vowel_letters = ['a', 'e', 'i', 'o', 'u']
        while l < r:
            if s[l].lower() not in vowel_letters:
                l += 1
            elif s[r].lower() not in vowel_letters:
                r -= 1
            else:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
        s = ''.join(s)
        return s
            
# @lc code=end

