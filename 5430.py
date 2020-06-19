class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.curr = 0

    def visit(self, url: str) -> None:
        self.curr += 1
        self.history = self.history[:self.curr]
        self.history.append(url)

    def back(self, steps: int) -> str:
        self.curr = max(self.curr - steps, 0)
        
        return self.history[self.curr]

    def forward(self, steps: int) -> str:
        n = len(self.history)
        self.curr = min(self.curr + steps, n-1)
        
        return self.history[self.curr]

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)