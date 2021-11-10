from typing import List


class Solution:
    def findPoisonedDuration(self, timeSeries: List[int],
                             duration: int) -> int:
        count = 0

        for pre, cur in [(timeSeries[i], timeSeries[i + 1])
                         for i in range(len(timeSeries) - 1)]:
            count += min(cur - pre, duration)
        return count + duration
