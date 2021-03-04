from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        c2l = defaultdict(list)
        
        for s in strs:
            key = "".join(sorted(s))
            c2l[key].append(s)
        
        return list(c2l.values())