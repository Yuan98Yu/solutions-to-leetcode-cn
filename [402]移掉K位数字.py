class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        """ 贪心+暴力
        """

        if k == 0:
            new_num = num.lstrip('0')
            if not new_num:
                new_num = '0'
            return new_num
        if not num or len(num) == k:
            return '0'

        p = len(num) - 1
        for i in range(len(num)-1):
            if num[i] > num[i+1]:
                p = i
                break
        new_num = num[:p] + num[p+1:]

        return self.removeKdigits(new_num, k-1)
    
    def removeKdigits2(self, num: str, k: int) -> str:
        """ 贪心+单调栈
        """

        stack = list()

        for digit in num:
            while k and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            
            stack.append(digit)

        if k > 0:
            stack = stack[:-k]
        return "".join(stack).lstrip('0') or '0'