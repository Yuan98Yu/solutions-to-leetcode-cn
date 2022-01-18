from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l, r = 0, len(letters)

        while l < r:
            mid = (l+r) // 2
            if letters[mid] <= target:
                l = mid + 1
            else:
                r = mid

        return letters[r%len(letters)]
