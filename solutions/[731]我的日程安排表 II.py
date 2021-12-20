from sortedcontainers import SortedDict


class MyCalendarTwo:
    def __init__(self):
        self.records = SortedDict()

    def book(self, start: int, end: int) -> bool:
        count = 0
        self.records[start] = self.records.get(start, 0) + 1
        self.records[end] = self.records.get(end, 0) - 1
        for key, value in self.records.items():
            if key >= end:
                break
            count += value
            if key >= start and count > 2:
                self.records[start] = self.records.get(start, 0) - 1
                self.records[end] = self.records.get(end, 0) + 1
                return False

        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)