#
# @lc app=leetcode.cn id=763 lang=python3
#
# [763] 划分字母区间
#

# @lc code=start
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        '''合并区间'''
        letters = [[len(S), 0] for i in range(26)]

        for idx, c in enumerate(S):
            letter_idx = ord(c)-ord('a')
            letters[letter_idx][0] = min(letters[letter_idx][0], idx)
            letters[letter_idx][1] = max(letters[letter_idx][1], idx)
        i = 0
        while i < len(letters):
            if letters[i][0] == len(S):
                del letters[i]
            else:
                i += 1
        letters.sort()

        ans = list()
        left, right = letters[0]
        for (c_left, c_right) in letters:
            if right >= c_left:
                right = max(right, c_right)
            else:
                ans.append(right - left + 1)
                left, right = c_left, c_right
        ans.append(right - left + 1)

        return ans
        
# @lc code=end

