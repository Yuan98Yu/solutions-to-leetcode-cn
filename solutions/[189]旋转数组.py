"""环状替换理解 https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
方法一中使用额外数组的原因在于如果我们直接将每个数字放至它最后的位置，这样被放置位置的元素会被覆盖从而丢失。因此，从另一个角度，我们可以将被替换的元素保存在变量 \textit{temp}temp 中，从而避免了额外数组的开销。

我们从位置 00 开始，最初令 \textit{temp}=\textit{nums}[0]temp=nums[0]。根据规则，位置 00 的元素会放至 (0+k)\bmod n(0+k)modn 的位置，令 x=(0+k)\bmod nx=(0+k)modn，此时交换 \textit{temp}temp 和 \textit{nums}[x]nums[x]，完成位置 xx 的更新。然后，我们考察位置 xx，并交换 \textit{temp}temp 和 \textit{nums}[(x+k)\bmod n]nums[(x+k)modn]，从而完成下一个位置的更新。不断进行上述过程，直至回到初始位置 00。

容易发现，当回到初始位置 00 时，有些数字可能还没有遍历到，此时我们应该从下一个数字开始重复的过程，可是这个时候怎么才算遍历结束呢？我们不妨先考虑这样一个问题：从 00 开始不断遍历，最终回到起点 00 的过程中，我们遍历了多少个元素？

由于最终回到了起点，故该过程恰好走了整数数量的圈，不妨设为 aa 圈；再设该过程总共遍历了 bb 个元素。因此，我们有 an=bkan=bk，即 anan 一定为 n,kn,k 的公倍数。又因为我们在第一次回到起点时就结束，因此 aa 要尽可能小，故 anan 就是 n,kn,k 的最小公倍数 \text{lcm}(n,k)lcm(n,k)，因此 bb 就为 \text{lcm}(n,k)/klcm(n,k)/k。

"""
from typing import List
import math


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        b = math.gcd(n, k)

        for i in range(b):
            p = i
            prev_num = nums[p]
            while True:
                p = (p+k) % n
                nums[p], prev_num = prev_num, nums[p]
                if p == i:
                    break
