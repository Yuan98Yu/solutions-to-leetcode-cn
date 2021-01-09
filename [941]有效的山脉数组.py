from typing import List


class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3 or A[0] >= A[1]:
            return False
        
        flag = True
        for i in range(2, len(A)):
            pre_num, num = A[i-1], A[i]
            if pre_num == num:
                return False
            if flag and pre_num > num:
                flag = False
            if not flag and pre_num < num:
                return False

        return not flag
