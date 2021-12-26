from typing import List
from collections import defaultdict
from functools import reduce


class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        num2poslist = defaultdict(list)
        for i, num in enumerate(arr):
            num2poslist[num].append(i)

        ans_dict = dict()
        ans = list()
        for i, num in enumerate(arr):
            pre_ans = ans_dict.get(num, None)
            if pre_ans is None:
                count = reduce(lambda count, next_pos: count+abs(next_pos-i), num2poslist[num], 0)
                ans_dict[num] = (count, i, 0)
                ans.append(count)
            else:
                pre_count, pre_i, pre_pos = pre_ans
                pos = pre_pos + 1
                count = pre_count + (2* pos - len(num2poslist[num])) * (i-pre_i)
                ans_dict[num] = (count, i, pos)
                ans.append(count)
                
                
        return ans
