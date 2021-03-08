class Solution:
    def minTime(self, time: List[int], m: int) -> int:
        lo, hi = 0, sum(time)
        while lo < hi:
            mid = (lo+hi) // 2
            if self.check(time, mid, m):
                hi = mid
            else:
                lo = mid + 1
        return lo

    def check(self, time, mid, m):
        cnt = 0
        max_ = 0
        s = 0
        for t in time:
            max_ = max(max_, t)            
            s += t
            if s - max_ > mid:
                cnt += 1
                s = t
                max_ = t
