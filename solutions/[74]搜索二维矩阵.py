from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def binary_search(arr):
            l, r = 0, len(arr)
            while l < r:
                mid = (l+r) // 2
                if arr[mid] > target:
                    r = mid
                else:
                    l = mid + 1
            return l - 1
        
        v_p = binary_search([line[0] for line in matrix])
        l_p = binary_search(matrix[v_p])

        # print(v_p, l_p, matrix[v_p][l_p])
        return matrix[v_p][l_p] == target
