from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        arr.append(1001)
        counts = set()

        pre_num, count = arr[0], 0
        for num in arr:
            if num == pre_num:
                count += 1
            elif count in counts:
                return False
            else:
                counts.add(count)
                pre_num = num
                count = 1
        return True