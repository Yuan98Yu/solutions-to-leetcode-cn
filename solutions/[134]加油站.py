from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        i = 0

        while i < len(gas):
            sum = 0
            for pj in range(i, i+len(gas)):
                j = pj % len(gas)
                sum += gas[j] - cost[j]
                if sum < 0:
                    i = pj + 1
                    break
                if pj - i + 1 == len(gas):
                    return i
                print(i, j)
        
        return -1