from collections import defaultdict
from itertools import product


class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        c_idxs = defaultdict(list)
        for i, c in enumerate(ring):
            c_idxs[c].append(i)

        memo = [[float('inf')]*len(ring) for _ in range(len(key))]
        for c_idx in c_idxs[key[0]]:
            memo[0][c_idx] = min(c_idx, len(ring)-c_idx) + 1
        for i in range(1, len(key)):
            for c_idx in c_idxs[key[i]]:
                for pre_idx in c_idxs[key[i-1]]:
                    memo[i][c_idx] = min(memo[i][c_idx], memo[i-1][pre_idx] +
                                         min(abs(c_idx-pre_idx), len(ring)-abs(c_idx-pre_idx))+1)
        # print(memo)
        return min(memo[len(key)-1])
