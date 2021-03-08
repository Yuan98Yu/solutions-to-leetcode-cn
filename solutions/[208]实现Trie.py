class TrieNode(object):
    """ 一个 Trie 节点。其能够通过一个字符查询到相应的子节点，因而使用字典实现
    """

    def __init__(self) -> None:
        super(TrieNode, self).__init__()
        self._dict = dict()
        self._end = False

    def insert(self, char: str):
        self._dict[char] = TrieNode()
        return self.get(char)
    
    def get(self, char: str):
        return self._dict.get(char)
    
    def set_end(self, end: bool) -> None:
        self._end = end
    
    def is_word(self) -> bool:
        return self._end


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.root
        for c in word:
            node = cur.get(c)
            if node is None:
                node = cur.insert(c)
            cur = node
        cur.set_end(True)


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.root
        for char in word:
            cur = cur.get(char)
            if cur is None:
                break
        return cur is not None and cur.is_word()


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self.root
        for char in prefix:
            cur = cur.get(char)
            if cur is None:
                break
        return cur is not None


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)