from sortedcontainers import SortedDict


class MyCalendarThree:
    def __init__(self):
        self.records = SortedDict()
        self.max_count = 0

    def book(self, start: int, end: int) -> int:
        count = 0
        self.records[start] = self.records.get(start, 0) + 1
        self.records[end] = self.records.get(end, 0) - 1
        for key, value in self.records.items():
            if key >= end:
                break
            count += value
            self.max_count = max(self.max_count, count)

        return self.max_count


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)