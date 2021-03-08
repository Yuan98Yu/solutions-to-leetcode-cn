#
# @lc app=leetcode.cn id=621 lang=python3
#
# [621] 任务调度器
#
from typing import List
from collections import Counter
# @lc code=start
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = Counter(tasks)
# @lc code=end

