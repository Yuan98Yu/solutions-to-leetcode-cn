class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.stack = list()


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if not self.stack:
            self.head = x
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        tmp = list()
        while self.stack:
            tmp.append(self.stack.pop())
        
        ret = tmp.pop()
        self.head = tmp[-1] if tmp else None
        while tmp:
            self.stack.append(tmp.pop())
        
        print(self.stack)
        return ret


    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.head


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack) == 0
