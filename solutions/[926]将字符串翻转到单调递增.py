class Solution(object):
    def minFlipsMonoIncr(self, s: str):
        """
        :type s: str
        :rtype: int
        """
        l_one_count, r_zero_count = 0, s.count('0')
        ans = l_one_count + r_zero_count
        for c in s:
            if c == '1':
                l_one_count += 1
            else:
                r_zero_count -= 1
            ans = min(ans, l_one_count + r_zero_count)
        
        return ans
