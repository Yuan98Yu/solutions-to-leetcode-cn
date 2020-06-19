#
# @lc app=leetcode.cn id=365 lang=python3
#
# [365] 水壶问题
#


# @lc code=start
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        actions_dict = {
            'empty_x': lambda _x, _y: (0, _y),
            'empty_y': lambda _x, _y: (_x, 0),
            'full_x': lambda _x, _y: (x, _y),
            'full_y': lambda _x, _y: (_x, y),
            'x2y': lambda _x, _y: (max(0, _x - (y - _y)), min(y, _y + _x)),
            'y2x': lambda _x, _y: (min(x, _x + _y), max(0, _y - (x - _x)))
        }

        def dump(state, action):
            new_state = action(*state)
            return tuple(new_state)

        def is_success(state):
            return state[0] == z or state[1] == z or sum(state) == z

        def dfs():
            stack = [(0, 0)]
            memo = set()
            while stack:
                state = stack.pop()
                if is_success(state):
                    return True
                if state in memo:
                    continue
                memo.add(state)
                for action in actions_dict.values():
                    stack.append(dump(state, action))
            return False

        return dfs()


# @lc code=end
