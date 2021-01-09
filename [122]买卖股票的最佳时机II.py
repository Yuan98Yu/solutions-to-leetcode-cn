from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buy_cost = 99999
        for price in prices:
            if price > buy_cost:
                profit += price - buy_cost
            buy_cost = price

        return profit