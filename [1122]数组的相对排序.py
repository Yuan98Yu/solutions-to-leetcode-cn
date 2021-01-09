from typing import List


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        key1_dict = dict()
        for i, num in enumerate(arr2):
            key1_dict[num] = i

        return sorted(arr1,
                      key=lambda num: (key1_dict.get(num, float('inf')), num)
                      )
