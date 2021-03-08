from typing import List


class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def count_1(num):
            if num == 0:
                return 0
            return count_1(num>>1) + (num&1)
        # for num in arr:
        #     print(num, count_1(num))
        return sorted(arr, key= lambda x: (count_1(x), x))
