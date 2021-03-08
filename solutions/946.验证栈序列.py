#
# @lc app=leetcode.cn id=946 lang=python3
#
# [946] 验证栈序列
#

# @lc code=start
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        s = list()
        pushed_i = 0
        popped_i = 0
        while pushed_i < len(pushed):
            if s and s[-1] == popped[popped_i]:
                popped_i += 1
                s.pop()
            else:
                s.append(pushed[pushed_i])
                pushed_i += 1

        while popped_i < len(popped):
            if not s[-1] == popped[popped_i]:
                break
            else:
                popped_i += 1
                s.pop()

        return not s

# @lc code=end

