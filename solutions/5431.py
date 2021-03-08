class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int,
                target: int) -> int:
        def dfs(i, pre_color, target):
            if i == m:
                return 0
            if target == 0:
                if houses[i] == 0:
                    return cost[i][pre_color - 1] + dfs(
                        i + 1, pre_color, target)
                elif houses[i] == pre_color:
                    return dfs(i + 1, pre_color, target)
                else:
                    return 999999
            if target < 0:
                return 999999

            if houses[i] == 0:
                if pre_color == 0:
                    min_cost = 999999
                else:
                    min_cost = dfs(i + 1, pre_color,
                                   target) + cost[i][pre_color - 1]
                for color in range(1, n + 1):
                    if color == pre_color:
                        continue
                    else:
                        min_cost = min(
                            min_cost,
                            dfs(i + 1, color, target - 1) + cost[i][color - 1])

                return min_cost
            else:
                if pre_color == houses[i]:
                    new_target = target
                else:
                    new_target = target - 1

                return dfs(i + 1, houses[i], new_target)

        ans = dfs(0, 0, target)
        return ans if ans < 999999 else -1