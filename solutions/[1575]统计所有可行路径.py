from typing import List


""" Solutions 1
"""
# class Solution:
#     def countRoutes(self, locations: List[int], start: int, finish: int,
#                     fuel: int) -> int:
#         N = len(locations)
#         memo = [[-1] * (fuel+1) for _ in range(N)]

#         def helper(pos, fuel):
#             if memo[pos][fuel] != -1:
#                 return memo[pos][fuel]

#             reached = get_reached(pos, fuel)
#             memo[pos][fuel] = 0 if pos != finish else 1
#             if reached:
#                 for next in reached:
#                     memo[pos][fuel] += helper(
#                         next, fuel - abs(locations[next] - locations[pos]))

#             return memo[pos][fuel]

#         def get_reached(pos, fuel):
#             reached = list()
#             for i, loc in enumerate(locations):
#                 if pos != i and abs(locations[pos] - loc) <= fuel:
#                     reached.append(i)
#             return reached
        
#         return helper(start, fuel) % 1000000007


"""Solution 2
"""
class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int,
                    fuel: int) -> int:
        N = len(locations)
        memo = [[-1] * (fuel+1) for _ in range(N)]

        def helper(pos, rest):
            if memo[pos][rest] != -1:
                return memo[pos][rest]
            
            if abs(locations[pos]-locations[finish]) > rest:
                memo[pos][rest] = 0
                return memo[pos][rest]

            memo[pos][rest] = 0 if pos != finish else 1
            for next, loc in enumerate(locations):
                cost = abs(locations[pos] - loc)
                if next != pos and cost <= rest:
                    memo[pos][rest] += helper(
                        next, rest - cost)

            return memo[pos][rest]
        
        return helper(start, fuel) % 1000000007
