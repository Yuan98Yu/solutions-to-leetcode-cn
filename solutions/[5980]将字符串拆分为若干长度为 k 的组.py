from typing import List


class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = list()
        for i in range(k, len(s)+1, k):
            ans.append(s[i-k:i])
        res = len(s) % k
        if res > 0:
            ans.append(s[-res:]+fill*(k-res))
        return ans