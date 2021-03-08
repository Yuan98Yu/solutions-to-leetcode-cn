from functools import reduce
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        def factorial(a, b):
            return reduce(lambda x,y: x*y, range(a, b+1), 1)
        if n == 0:
            return 1
        if n == 1:
            return 10
        elif n < 0:
            return 0
        elif n > 10:
            return self.countNumbersWithUniqueDigits(10)
        else:
            return 9*factorial(9-n+2, 9) + self.countNumbersWithUniqueDigits(n-1)