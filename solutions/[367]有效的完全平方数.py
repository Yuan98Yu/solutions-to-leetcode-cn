class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 1, num+1

        while l < r:
            mid = (l+r) // 2
            pow = mid ** 2
            if pow < num:
                l = mid + 1
            elif pow > num:
                r = mid 
            else:
                return True
        
        return False