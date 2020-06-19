#
# @lc app=leetcode.cn id=224 lang=python3
#
# [224] 基本计算器
#

# @lc code=start
class Solution:
    def __init__(self):
        self.opts = {
            '+': 0,
            '-': 0,
            '*': 1,
            '/': 1,
            '(': 2,
            ')': 3
        }

    def calculate(self, s: str) -> int:
        stack = list()
        num = ''
        
        for c in s:
            if c in self.opts.keys():
                print(c)
                if num:
                    stack.append(num)
                    num = ''
                if self.opts[c] <= self.opts[stack[-1]]:
                    num1 = stack.pop()
                    opt = stack.pop()
                    num2 = stack.pop()
                    stack.append(eval(num1+opt+num2))               
                stack.append(c)
            elif c == ' ':
                continue
            else:
                num += c
        return eval(''.join(stack))

# @lc code=end

