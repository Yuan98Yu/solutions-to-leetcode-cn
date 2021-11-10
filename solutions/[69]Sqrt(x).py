class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 1, x+1

        while l < r:
            mid = (l+r) // 2
            pow = mid ** 2
            if pow > x:
                r = mid
            else:
                l = mid + 1
        
        return l-1
