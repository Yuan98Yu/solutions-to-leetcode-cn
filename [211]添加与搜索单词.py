class TrieNode:
    def __init__(self) -> None:
        super(TrieNode, self).__init__()
        self._dict = dict()
        self.end = False
    
    def insert(self, char):
        self._dict[char] = TrieNode()
        return self.get(char)

    def get(self, char):
        return self._dict.get(char)
    
    def get_all(self):
        return self._dict.values()

    def search(self, word):
        if not word:
            return self.end
        
        c = word[0]
        if c != '.':
            node = self.get(c)
            return node is not None and node.search(word[1:])
        else:
            for node in self._dict.values():
                if node.search(word[1:]):
                    return True
            return False

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.root
        for c in word:
            node = cur.get(c)
            if node is None:
                node = cur.insert(c)
            cur = node
        cur.end = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.root.search(word)




# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)