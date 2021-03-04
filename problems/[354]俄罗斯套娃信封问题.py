from typing import *
from bisect import bisect_left


class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes = sorted(envelopes, key= lambda item: (item[0], -item[1]))
        return self.__len_of_longest_incremental_subsequence(envelopes)

    def __len_of_longest_incremental_subsequence(self, envelopes):
        memo = [envelopes[0][1]]

        for i in range(1, len(envelopes)):
            num = envelopes[i][1]
            if num > memo[-1]:
                memo.append(num)
            else:
                idx = bisect_left(memo, num)
                memo[idx] = num

        return len(memo)
