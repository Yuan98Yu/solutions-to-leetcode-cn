from typing import List
import heapq


class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        q = [(-x ** 2 - y ** 2, i) for i, (x, y) in enumerate(points[:K])]
        heapq.heapify(q)
        
        n = len(points)
        for i in range(K, n):
            x, y = points[i]
            dist = -x ** 2 - y ** 2
            heapq.heappushpop(q, (dist, i))
        
        ans = [points[i] for (_, i) in q]
        return ans
