#
# @lc app=leetcode.cn id=336 lang=python3
#
# [336] 回文对
#

# @lc code=start
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ans = list()
        hashmap = dict()
        for word in words:
            if word in hashmap.keys():
                

# @lc code=end

