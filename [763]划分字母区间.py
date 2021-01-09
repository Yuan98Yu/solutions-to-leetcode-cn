from typing import List


class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        p_of_c_end = [-1] * 26
        for i, c in enumerate(S):
            p_of_c_end[ord(c)-ord('a')] = i
        
        ans = list()
        start, end = 0, 0
        for i, c in enumerate(S):
            end = max(end, p_of_c_end[ord(c)-ord('a')])

            if i == end:
                ans.append(end-start+1)
                start = end + 1
        
        return ans
