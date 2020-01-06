#
# @lc app=leetcode.cn id=151 lang=python3
#
# [151] 翻转字符串里的单词
#

# @lc code=start
import re

class Solution:
    def reverseWords(self, s: str) -> str:
        words = re.findall(r'[^ ]+', s)
        words.reverse()
        return ' '.join(words)
# @lc code=end

