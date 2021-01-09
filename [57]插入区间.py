from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # 1 找到新区间插入位置
        insert_p = len(intervals)
        for i, (_, right) in enumerate(intervals):
            if newInterval[0] > right:
                insert_p = i + 1
                break
        intervals.insert(insert_p, newInterval)

        # 2 合并重叠区间
        right = newInterval[1]
        left_p = insert_p+1
        for i in range(insert_p+1, len(intervals)):
            if right < intervals[i][0]:
                left_p = i
                break
            else:
                right = max(right, intervals[i][1])
        return intervals[:insert_p] + [[newInterval[0], right]] + intervals[left_p:]
