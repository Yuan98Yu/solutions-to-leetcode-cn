#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] 用队列实现栈
#

# @lc code=start
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = list()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        q_size = len(self.queue)
        self.queue.append(x)
        for _ in range(q_size):
            tail = self.queue.pop(0)
            self.queue.append(tail)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.pop(0)
        

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end

