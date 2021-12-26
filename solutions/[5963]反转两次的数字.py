class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        return num < 10 or num % 10 != 0