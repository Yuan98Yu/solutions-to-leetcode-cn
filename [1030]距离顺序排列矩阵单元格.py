from typing import List
from itertools import product


class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        def is_coor_valid(r, c):
            return 0 <= r < R and 0 <= c < C
        
        ans = list()

        for dis in range(0, R+C):
            for r_dis in range(0, dis+1):
                c_dis = dis - r_dis
                r_signs = [-1, 1] if r_dis != 0 else [1]
                c_signs = [-1, 1] if c_dis != 0 else [1]
                for r_sign, c_sign in product(r_signs, c_signs):
                    r, c = r0 + r_sign*r_dis, c0 + c_sign*c_dis
                    if is_coor_valid(r, c):
                        ans.append([r, c])
        
        return ans