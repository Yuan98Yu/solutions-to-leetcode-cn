from typing import List


class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        memo = [0] * n
        memo[-1] = questions[-1][0]

        for i in range(n-2, -1, -1):
            val, power = questions[i]
            memo[i] = memo[i+power+1] + val if i+power+1 < n else val
            memo[i] = max(memo[i+1], memo[i])

        return max(memo)
