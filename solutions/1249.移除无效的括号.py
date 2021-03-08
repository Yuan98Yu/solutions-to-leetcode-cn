#
# @lc app=leetcode.cn id=1249 lang=python3
#
# [1249] 移除无效的括号
#

# @lc code=start
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        ans = list()
        stack = list()

        for c in s:
            if c == '(':
                stack.append('(')
            elif c == ')':
                if not stack: 
                    tmp = -1
                    while tmp != '(':
                        tmp = stack.pop()
                        ans.append(tmp)
                else:
                    continue
            else:
                stack.append(c)
        while stack:
            ans.append(stack.pop())
        
        ans.reverse()
        return ''.join(ans)

# @lc code=end

