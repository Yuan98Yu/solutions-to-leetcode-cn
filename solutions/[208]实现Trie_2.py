N = 26

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = [None] * N
        self.is_end = False


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        c2i = ord(word[0]) - ord('a')
        if self.children[c2i] is None:
            self.children[c2i] = Trie()
        cur = self.children[c2i]
        if len(word) == 1:
            cur.set_end(True)
        else:
            cur.insert(word[1:])


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self
        for char in word:
            c2i = ord(char) - ord('a')
            cur = cur.children[c2i]
            if cur is None:
                return False
        return cur.is_word()


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self
        for char in prefix:
            c2i = ord(char) - ord('a')
            cur = cur.children[c2i]
            if cur is None:
                return False
        return True
    
    def set_end(self, bool) -> None:
        self.is_end = bool

    def is_word(self) -> bool:
        return self.is_end
