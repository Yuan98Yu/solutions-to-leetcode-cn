from typing import List


class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        ans = [0] * len(A)
        i, j = 0, 1
        while i < len(A) and j < len(A):
            if A[i] % 2 == 0:
                ans[i] = A[i]
                i += 2
            elif A[j] % 2 == 1:
                ans[j] = A[j]
                j += 2
            else:
                ans[i], ans[j] = A[j], A[i]
                i += 2
                j += 2
        for idx in range(i, len(A), 2):
            ans[idx] = A[idx]
        for idx in range(j, len(A), 2):
            ans[idx] = A[idx]
        return ans