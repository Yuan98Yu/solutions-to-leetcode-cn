from typing import List


class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        ans = 0
        inventory = sorted(inventory, reverse=True) + [0]
        pre_val = inventory[0]
        pre_count = 1
        for val in inventory[1:]:
            pre_max_orders = (pre_val - val) * pre_count
            if pre_max_orders < orders:
                ans += (pre_val + val + 1) * (pre_val - val) // 2 * pre_count
                orders -= pre_max_orders
                # print(pre_val, val+1, pre_count)
            else:
                turns = orders // pre_count
                ans += (pre_val * 2 - turns + 1) * turns // 2 * pre_count + (
                    pre_val - turns) * (orders % pre_count)
                # print(pre_val, pre_val-turns+1, pre_count)
                # print(pre_val-turns, orders % pre_count)
                break
            pre_val = val
            pre_count += 1

        return ans % 1000000007
