import heapq
"""文档字符串测试

    袁宇
    2020.12.15
"""


class Solution:
    """A class with standard leetcode solution templete
    
    """

    def monotoneIncreasingDigits(self, N: int) -> int:
        """返回一个不小于 N 的递增数字

        使用贪心算法

        Args:
            N: An integer
        
        Returns:
            An integer(<=N) with monotone increasing digits
        """

        N_list = list()
        while N:
            N_list.append(N % 10)
            N //= 10
        N_list.reverse()
        min_heap = N_list.copy()
        heapq.heapify(min_heap)

        ans = 0
        flag = True
        for digit in N_list:
            ans *= 10
            # 贪心选择当前可选的最大的数字
            cur_d = heapq.heappop(min_heap) if flag else 9
            ans += cur_d
            if cur_d < digit:
                flag = False

        return ans