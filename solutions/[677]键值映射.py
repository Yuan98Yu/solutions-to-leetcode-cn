class Node:
    def __init__(self, val: int = 0) -> None:
        self.val = val
        self.children = [None] * 26
    
    def insert(self, key: str, val: int):
        c2i = ord(key[0]) - ord('a')
        if self.children[c2i] is None:
            self.children[c2i] = Node()
        if len(key) == 1:
            self.children[c2i].val = val
        else:
            self.children[c2i].insert(key[1:], val)
    
    def get(self, prefix: str):
        cur = self
        for c in prefix:
            c2i = ord(c) - ord('a')
            cur = cur.children[c2i]
            if cur is None:
                return None
        return cur


class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()


    def insert(self, key: str, val: int) -> None:
        self.root.insert(key, val)

    def sum(self, prefix: str) -> int:
        def dfs(root: Node) -> int:
            if root is None:
                return 0
            
            sum = root.val
            for node in root.children:
                sum += dfs(node)
            return sum

        cur = self.root.get(prefix)
        return dfs(cur)



# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)