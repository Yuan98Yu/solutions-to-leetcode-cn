class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        count1, count2 = 0, 0
        pre = '0'
        for c in s:
            if c == pre:
                count2 += 1
            else:
                ans += min(count1, count2)
                count1, count2 = count2, 1
                pre = c
        ans += min(count1, count2)
        return ans
