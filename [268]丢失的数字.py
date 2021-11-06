'''
Author: your name
Date: 2021-11-06 21:42:59
LastEditTime: 2021-11-06 21:45:32
LastEditors: your name
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \solutions-to-leetcode-cn\[268]丢失的数字.py
'''
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return (1 + n) * n // 2 - sum(nums)
